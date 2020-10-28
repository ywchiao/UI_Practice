#include <iostream>

#include "union.h"

int main(int argc, char *argv[]) {
    mix m;

    std::cout << "Union size: " << sizeof(m) << std::endl;
    std::cout << "  sizeof(char *): " << sizeof(char *) << std::endl;
    std::cout << "  sizeof(char): " << sizeof(char) << std::endl;
    std::cout << "  sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "  sizeof(float): " << sizeof(float) << std::endl;
}

// union.cpp
