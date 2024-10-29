#include <iostream>
#include <math.h>

int calculate(long long left, long long right, long long target, int depth = 1) {
    if (left == right) {
        return depth;
    }

    long long mid1 = left + (right - left) / 3;
    long long mid2 = right - (right - left) / 3;

    if (mid1 + 1 <= target && target < mid2)
        return depth;


    depth++;
    if (target <= mid1)
    {
        return calculate( left, mid1, target, depth);
    }
    else {
        return calculate( mid2, right, target, depth);
    }
}

int main()
{
    short pow;
    std::cin >> pow;
    long long n;
    std::cin >> n;

    long long length = std::pow(3, pow);

    for (long long i = 0; i < n; i++)
    {
        long long current;
        std::cin >> current;
        std::cout << calculate(0, length - 1, current - 1) << "\n";
    }
}
