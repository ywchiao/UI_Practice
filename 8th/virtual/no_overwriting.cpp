#include <iostream>

class Base {
public:
  void say_hi();
};

void Base::say_hi() {
  std::cout <<
    "Hello from Base." <<
    std::endl;
}

class Derived : public Base {
};

int main() {
    Derived derived;
    Derived *p_derived = &derived;
    Base *p_base = &derived;

    p_derived->say_hi();
    p_base->say_hi();
}
