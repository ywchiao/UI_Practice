#include <iostream>

int counter = 0;

void addOne() {
    counter ++;
}

int main(int argc, char *argv[]) {
    std::cout << "counter =";

    for (int i = 0; i < 3; i ++) {
        std::cout << " " << counter;
        addOne();
    }

    std::cout << " " << std::endl;
}
