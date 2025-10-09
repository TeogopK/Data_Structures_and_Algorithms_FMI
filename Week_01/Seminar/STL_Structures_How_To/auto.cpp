#include <iostream>
#include <vector>

// it can also be a return type
auto f() {
    return 1;
}

int main() {
    // The auto keyword directs the compiler to use the initialization expression of a declared variable,
    // or lambda expression parameter, to deduce its type.
    // Useful for iterators, lambdas, and complex types.
    // https://learn.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-170#remarks
    auto v1 = std::vector<int>(100, 0);
    auto v2 = v1;

    auto member = v1[0];
    f();
}