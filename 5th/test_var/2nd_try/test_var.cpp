#include <iostream>

#include "add_one.h"

int main(int argc, char *argv[]) {
    std::cout << "counter =";

    for (int i = 0; i < 3; i ++) {
        std::cout << " " << counter;
        addOne();
    }

    std::cout << " " << std::endl;
}
