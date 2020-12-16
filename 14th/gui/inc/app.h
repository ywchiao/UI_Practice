
#ifndef __APP_H__
#define __APP_H__

#include <map>
#include <memory>
#include <queue>
#include <string>

#include "SDL.h"

#include "event.h"
#include "listener.h"
#include "sprite_sheet.h"
#include "text.h"

#define ENV_SYMBOL_STR(symbol)   #symbol
#define ENV_SYMBOL(symbol)       ENV_SYMBOL_STR(symbol)

class App : public Listener {
    public:
        App(const std::string&);
        ~App();

    public:
        void hello(void);

        void start(void);
        void version();

        void add_listener(const std::string&, Listener *);

    public:
        int on(std::shared_ptr<Event>);

    private:
        int on_left_click_(std::shared_ptr<Event>);
        int on_right_click_(std::shared_ptr<Event>);

    private:
        void loop_(void);

        void dispatch_(void);

        void get_input_();
        void get_mouse_(SDL_Event&);

        void layout_background_();

        void tile_page_();
        void tile_quad_(int, int);

    private:
        int page_x_;
        int page_x_max_;
        int page_y_;
        int page_y_max_;

        SDL_Renderer *renderer_;
        SDL_Surface *surface_;
        SDL_Window *window_;

    private:
        SpriteSheet *sprite_world_;
        Text *text_;

    private:
        bool end_;

        std::map<std::string, Listener *> listener_;
        std::map<std::string, int (App::*)(std::shared_ptr<Event>)> table_;
        std::queue<std::shared_ptr<Event>> queue_;

    private:
        std::string invoked_;
};

#endif

// app.h
