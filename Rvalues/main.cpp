#include <iostream>

class A {
    public:
    A() {}
    A(const A& copy) {
        std::cout << "This is A's copy constructor\n";
    }
};

class B {
    public:
    B() {}
    B(const B& copy) {
        std::cout << "This is B's copy constructor\n";
    }
    B(const B&& copy) {
        std::cout << "This is B's move constructor\n";
    }
};

class C {
    public:
    C() {}
    C(const C& copy) {
        std::cout << "This is C's copy constructor\n";
    }

    C(const C&& copy) = delete;
};
int main() {
    A a1;
    A a2 = std::move(a1);
    B b1;
    B b2 = std::move(b1);
    // This causes a compiler error.
    // C c1;
    // C c2 = std::move(c1);
}
