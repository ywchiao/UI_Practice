
#ifndef __APP_H__
#define __APP_H__

#include <string>

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

    private:
        void loop_(void);

    private:
        std::string invoked_;
};

#endif

// app.h
