#include<iostream>

// Is there a mistake here?
void redirect(int* ptr, int dest) {
    ptr = &dest;
}

struct Test {
    int value = 0;
    Test* next = nullptr;

    // forget cc and operator= for now
    ~Test() {
        delete next;
    }
};

int main() {
    int a = 10;
    int b = 12;
    int* ptr = &a;

    redirect(ptr, b);
    // never forget that the address will be different on every execution
    std::cout << &b << std::endl;
    std::cout << ptr << std::endl;

    // also const pointers
    const int* constPtr = &a;
    // *constPtr = 5; // error
    // constPtr = &b; // ok
    int const * f = &a;
    // *f = 5; // error
    // f = &b; // ok
    int const* const g = &a;
    // *g = 5; // error
    // g = &b; // error


    Test* t = new Test();
    t->value = 1;
    t->next = new Test();
    t->next->value = 2;
    t->next->next = new Test();

    delete t;
}