
#ifndef __APP_H__
#define __APP_H__

#include <map>
#include <memory>
#include <queue>
#include <string>

#include "event.h"
#include "listener.h"

#define ENV_SYMBOL_STR(symbol)   #symbol
#define ENV_SYMBOL(symbol)       ENV_SYMBOL_STR(symbol)

class App {
    public:
        App(const std::string&);
        ~App();

    public:
        void hello(void);

        void start(void);
        void version();

        void add_listener(const std::string&, Listener *);

    private:
        void loop_(void);

        void dispatch_(void);

        void get_input_();
        void get_mouse_();

    private:
        SDL_Window *window_;
        SDL_Surface *surface_;

    private:
        bool end_;

        std::map<std::string, Listener *> listener_;
        std::queue<std::shared_ptr<Event>> queue_;

    private:
        std::string invoked_;
};

#endif

// app.h
