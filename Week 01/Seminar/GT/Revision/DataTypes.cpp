#include <iostream>

int main() {
    // for specific sizes, use #include <stdint.h>
    // and use int8_t, int16_t, int32_t, int64_t...
    
    char c = 'a'; // 1 byte, values from -128 to 127
    short s = 1; // 2 bytes, values from -32,768 to 32,767
    // by standard, int is at least 16 bits, but it is usually 32 bits
    int i = 1; // 4 bytes, values from -2,147,483,648 to 2,147,483,647
    // by standard, long is at least 32 bits, but it is usually 32 bits
    long l = 1; // 4 bytes, values from -2,147,483,648 to 2,147,483,647
    // by standard, long long is at least 64 bits, but it is usually 64 bits
    long long ll = 1; // 8 bytes, values from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    float f = 1.0f; // 4 bytes, values from ~1.2E-38 to 3.4E+38, but it depends
    double d = 1.0; // 8 bytes, values from ~ 2.3E-308 to 1.7E+308, but it depends
    long double ld = 1.0; // it depends
    unsigned char uc = 'a'; // 1 byte, values from 0 to 255
    unsigned short us = 1; // 2 bytes, values from 0 to 65,535
    unsigned int ui = 1; // 4 bytes, values from 0 to 4,294,967,295
    unsigned long ul = 1; // 4 bytes, values from 0 to 4,294,967,295
    unsigned long long ull = 1; // 8 bytes, values from 0 to 18,446,744,073,709,551,615

    // watch out for overflowing
    int a = INT_MAX + 1;
    std::cout << (a == INT_MIN);
    // example:
    // store the sum of integers inside a long long variable
}