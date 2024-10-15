#include <iostream>

int main()
{
    // Using type "int" is ok since "a" and "b" are between 1 and 1000.
    int a, b;
    std::cin >> a >> b;

    std::cout << a + b;

    return 0;
}
