#include <iostream>
#include <vector>
#include <chrono> // For timing functions

// Pancake function
long long f_pancakes(long long t, const std::vector<int> &cooks = {2, 3, 5})
{
    long long pancakes = 0;
    for (int cook : cooks)
    {
        pancakes += t / cook;
    }
    return pancakes;
}

// Verbose Linear Search for pancake problem
long long linear_search_pancakes(long long target, const std::vector<int> &cooks)
{
    long long t = 0;
    while (true)
    {
        std::cout << "Checking f_pancakes(" << t << ") = " << f_pancakes(t, cooks) << std::endl;
        if (f_pancakes(t, cooks) >= target)
        {
            std::cout << "Found target at t = " << t << std::endl;
            return t;
        }
        t++;
    }
}

// Verbose Binary Search for pancake problem
long long binary_search_pancakes(long long target, const std::vector<int> &cooks)
{
    long long left = 0, right = 1e16, ans = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        std::cout << "Checking f_pancakes(" << mid << ") = " << f_pancakes(mid, cooks) << std::endl;
        if (f_pancakes(mid, cooks) >= target)
        {
            std::cout << "f_pancakes(" << mid << ") >= target, moving right boundary to mid - 1" << std::endl;
            ans = mid;
            right = mid - 1;
        }
        else
        {
            std::cout << "f_pancakes(" << mid << ") < target, moving left boundary to mid + 1" << std::endl;
            left = mid + 1;
        }
    }
    std::cout << "Found target at t = " << ans << std::endl;
    return ans;
}

int main()
{
    std::vector<int> cooks = {2, 3, 5};
    long long target_pancakes; // Try with 100'000

    std::cout << "Enter the target number of pancakes: ";
    std::cin >> target_pancakes;

    if (std::cin.fail())
    {
        target_pancakes = 100'000;
        std::cout << "Defaulting to target_pancakes = " << target_pancakes << std::endl;
    }

    // Time Linear Search for pancakes
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting Linear Search for pancakes..." << std::endl;
    long long result_linear_pancakes = linear_search_pancakes(target_pancakes, cooks);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_linear_pancakes = end - start;

    std::cout << std::endl;

    // Time Binary Search for pancakes
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting Binary Search for pancakes..." << std::endl;
    long long result_binary_pancakes = binary_search_pancakes(target_pancakes, cooks);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_binary_pancakes = end - start;

    std::cout << "Linear Search Result: The first moment we have more than " << target_pancakes << " pancakes is at: " << result_linear_pancakes << std::endl;
    std::cout << "Linear Search Time: " << duration_linear_pancakes.count() << " seconds" << std::endl;
    std::cout << "Binary Search Result: The first moment we have more than " << target_pancakes << " pancakes is at: " << result_binary_pancakes << std::endl;
    std::cout << "Binary Search Time: " << duration_binary_pancakes.count() << " seconds" << std::endl;

    return 0;
}
