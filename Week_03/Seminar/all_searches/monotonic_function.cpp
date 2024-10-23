#include <iostream>
#include <cmath>  // For pow function
#include <chrono> // For timing functions

// Define the monotonic function f(x)
long long f(long long x)
{
    return pow(x, 2) + x + 5;
}

// Verbose Linear Search on monotonic function
long long linear_search_f(long long target)
{
    long long i = 0;
    while (true)
    {
        // Note that the prints will be the main bottleneck in this function
        std::cout << "Checking f(" << i << ") = " << f(i) << std::endl;
        if (f(i) >= target)
        {
            std::cout << "Found target at i = " << i << std::endl;
            return i;
        }
        i++;
    }
}

// Verbose Binary Search on monotonic function
long long binary_search_f(long long target)
{
    long long left = 0, right = 2e9, ans = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        std::cout << "Checking f(" << mid << ") = " << f(mid) << std::endl;
        if (f(mid) >= target)
        {
            std::cout << "f(" << mid << ") >= target, moving right boundary to mid - 1" << std::endl;
            ans = mid;
            right = mid - 1;
        }
        else
        {
            std::cout << "f(" << mid << ") < target, moving left boundary to mid + 1" << std::endl;
            left = mid + 1;
        }
    }
    std::cout << "Found target at x = " << ans << std::endl;
    return ans;
}

int main()
{
    long long target = 1'975'313'001;

    std::cout << "Searching the smallest x for which f(x) > target: " << target;

    // Time Linear Search
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting Linear Search..." << std::endl;
    long long result_linear = linear_search_f(target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_linear = end - start;

    std::cout << std::endl;

    // Time Binary Search
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting Binary Search..." << std::endl;
    long long result_binary = binary_search_f(target);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_binary = end - start;

    std::cout << "Linear Search Result: The smallest x for which f(x) >= target is: " << result_linear << std::endl;
    std::cout << "Linear Search Time: " << duration_linear.count() << " seconds" << std::endl;
    std::cout << "Binary Search Result: The smallest x for which f(x) >= target is: " << result_binary << std::endl;
    std::cout << "Binary Search Time: " << duration_binary.count() << " seconds" << std::endl;

    return 0;
}
