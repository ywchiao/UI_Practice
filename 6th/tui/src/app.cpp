
#include <iostream>

#ifdef _WIN32
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
App::App(const std::string& name): invoked_(name) {
    initscr();              // 初始化視窗環境

    curs_set(0);            // 隱藏游標 (cursor)

    nodelay(stdscr, TRUE);  // 設定 getch() 為 *no delay* 狀態，
                            // 無論使用者有無按鍵，均直接返回

    keypad(stdscr, TRUE);   // 啟動游標鍵和功能鍵 (F1 ~ F12)
    noecho();               // 不要回應 (echo) 使用者輸入到螢幕上

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
    while (true) {  // 程式主迴圈 (main-loop)
        hello();               // 印出訊息

        refresh();             // 更新畫面

        if (getch() != ERR) {  // 取得使用者輸入
            break;
        }
    } // od
} // App::loop_()

// app.cpp
