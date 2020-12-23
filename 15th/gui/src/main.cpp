
#include "mouse_listener.h"

#include "app.h"

int main(int argc, char *argv[]) {
    MouseListener mouse_listener;

    App app{argv[0]};

    app.add_listener("click", &mouse_listener);
    app.add_listener("left_click", &app);
    app.add_listener("right_click", &app);

    app.start();

    return 0;
}

// main.cpp
