#include <iostream>

#include "union.h"

int main(int argc, char *argv[]) {
    mix m;

    m.i = 65;
    std::cout << "  union.str: " << (void *) m.str << std::endl;
    std::cout << "  union.c: " << m.c << std::endl;
    std::cout << "  union.i: " << m.i << std::endl;
    std::cout << "  unino.f: " << m.f << std::endl;
}

// union2.cpp
