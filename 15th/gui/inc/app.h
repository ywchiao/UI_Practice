
#ifndef __APP_H__
#define __APP_H__

#include <map>
#include <memory>
#include <queue>
#include <string>

#include "SDL.h"

#include "event.h"
#include "listener.h"
#include "outside.h"

#define ENV_SYMBOL_STR(symbol)   #symbol
#define ENV_SYMBOL(symbol)       ENV_SYMBOL_STR(symbol)

class App : public Listener {
    public:
        App(const std::string&);
        ~App();

    public:
        void start(void);
        void version();

        void add_listener(const std::string&, Listener *);

    public:
        int on(std::shared_ptr<Event>);

    private:
        void loop_(void);

        void dispatch_(void);

        void get_input_();
        void get_mouse_(SDL_Event&);

        void layout_land_(int, int);
        void layout_map_();
        void layout_objects_(int, int, int (&)[12][12]);

    private:
        SDL_Renderer *renderer_;
        SDL_Surface *surface_;
        SDL_Window *window_;

    private:
        static std::string const tiles_[];

        Outside *outside_;

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
