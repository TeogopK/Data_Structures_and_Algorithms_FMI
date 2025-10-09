#include <iostream>

long long sum = 0;

// Not optimized for tail recursion
void sum1toN(int N)
{
    if (N < 1)
        return;
    sum1toN(N - 1);
    sum += N;
}

// Optimized for tail recursion
void sum1toN_tail(int N)
{
    if (N < 1)
        return;
    sum += N;
    sum1toN(N - 1);
}