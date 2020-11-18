
#include "button.h"
#include "mouse_listener.h"

#include "app.h"

int main(int argc, char *argv[]) {
    MouseListener mouse_listener;

    App app{argv[0]};
    Button button(35, 20, 12, 1, " Ok ");

    app.add_listener("click", &mouse_listener);
    app.add_listener("pressed", &button);
    app.add_listener("released", &button);
    app.add_listener("repaint", &button);

    app.start();
}

// main.cpp
