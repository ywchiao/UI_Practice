
#include <iostream>
#include <string>

#ifdef _WIN32
#define PDC_NCMOUSE // for NCurses Mouse APIs
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "app.h"

// 函數 (方法) 的實作 (implementations)

/**
 *  App constructor.  Initialize the curses lib.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
App::App(const std::string& name): end_{ false }, invoked_{ name } {
    initscr();              // 初始化視窗環境

    curs_set(0);            // 隱藏游標 (cursor)

    cbreak();               // 關閉 line buffering

    nodelay(stdscr, TRUE);  // 設定 getch() 為 *no delay* 狀態，
                            // 無論使用者有無按鍵，均直接返回

    keypad(stdscr, TRUE);   // 啟動游標鍵和功能鍵 (F1 ~ F12)
    noecho();               // 不要回應 (echo) 使用者輸入到螢幕上

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
                            // 取得所有滑鼠事件

    refresh();              // 重繪螢幕
} // App::App()

/**
 *  App destructor.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
App::~App() {
    endwin();               // 回覆 console (terminal) 的原始狀態

    version();              // 印出目前的程式版本訊息
} // App::~App()


/**
 *  Register a Event Listener。
 *
 *  @param const std::string&: The reference of Event name.
 *  @param const Listener *: Pointer to the Event Listner.
 *  @return none.
 *  @since  0.1.0
 **/
void App::add_listener(const std::string& event, Listener *listener) {
    listener_[event] = listener;
} // App::add_listener

/**
 *  Print 'Hello'... messages on stdscr.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::hello() {
    mvprintw(10, 30, "Hello World !!!");
    mvprintw(11, 40, "--- from 'NCurses: The Dawn!'");
} // App::hello()

/**
 *  Starts the game.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::start() {
    loop_();
} // App::start()

/**
 *  Print the App's version info.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::version() {
    std::cout
        << ENV_SYMBOL(PROJECT_NAME) << " "
        << ENV_SYMBOL(VERSION_MAJOR) << "."
        << ENV_SYMBOL(VERSION_MINOR) << "."
        << ENV_SYMBOL(VERSION_PATCH) << "b"
        << ENV_SYMBOL(BUILD_NUMBER) << ". "
        << "bulit at "
        << ENV_SYMBOL(BUILD_TIME) << ", "
        << ENV_SYMBOL(BUILD_DATE)
        << std::endl;
} // App::version()

/**
 *  The main-loop of the game.  Game over when the loop ends.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::loop_() {
    while (!end_) {  // 程式主迴圈 (main-loop)
        hello();        // 印出訊息

        refresh();      // 更新畫面

        get_input_();   // 取得使用者輸入；轉換成 Event 物件
                        // 放進 Event queue (佇列)

        dispatch_();    // 處理 Event queue 裡的事件
    } // od
} // App::loop_()

/**
 *  Event processing loop.  Pop out Event from event queue,
 *  passing it to corresponding listeners, loop.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::dispatch_() {
    while (!queue_.empty()) {
        std::shared_ptr<Event> e = queue_.front();
        queue_.pop();

        listener_[e->event]->on(e);
    }
} // App::dispatch_()

/**
 *  Get user input from keyboard/mouse and put into event queue for
 *  later processing.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::get_input_() {
    int ch = getch();   // 取得使用者輸入

    switch (ch) {
        case KEY_MOUSE: // NCurses 將滑鼠對應到虛擬 KEY_MOUSE 鍵
            get_mouse_();   // 真正去取得滑鼠事件資料

            break;

        case 'q':
            end_ = true;

            break;

        default:
            break;
    }
} // App::get_input_()

/**
 *  Get mouse event, traslate into MouseEvent object, and put into
 *  event queue for later processing.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
void App::get_mouse_() {
    MEVENT event;   // NCurses 提供的 Mouse 事件資料結構 (struct)

    if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_CLICKED) {
            queue_.push(
                std::make_shared<Event>(
                    "click", event.x, event.y, event.z
                )
            );
        }
    }
} // App::get_mouse_()

// app.cpp
