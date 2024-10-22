#include <iostream>
#include <vector>
#include <cmath>

// Jump Search Function
int jumpSearch(const std::vector<int> &arr, int key)
{
    int N = arr.size();
    int block_size = std::sqrt(N); // Jump size is the square root of the array size
    int step = block_size;
    int prev = 0;

    while (arr[std::min(step, N) - 1] < key)
    {
        prev = step;
        step += block_size;
        if (prev >= N)
        {
            return -1; // Element not found
        }
    }

    // Perform linear search in the identified block
    while (arr[prev] < key)
    {
        prev++;
        if (prev == std::min(step, N))
        {
            return -1; // Element not found
        }
    }

    if (arr[prev] == key)
    {
        return prev;
    }

    return -1; // Element not found
}

// Verbose Jump Search Function
int jumpSearchVerbose(const std::vector<int> &arr, int key)
{
    int N = arr.size();
    int block_size = std::sqrt(N);
    std::cout << "Array length: " << N << ", Block size: " << block_size << std::endl;

    int step = block_size;
    int prev = 0;

    while (arr[std::min(step, N) - 1] < key)
    {
        std::cout << "Jumping to step " << std::min(step, N) << ": " << arr[std::min(step, N) - 1] << std::endl;
        prev = step;
        step += block_size;

        if (prev >= N)
        {
            std::cout << "Key is larger than the maximum element." << std::endl;
            return -1;
        }
    }

    std::cout << "Jumped interval: [" << arr[prev] << ", " << arr[std::min(step, N) - 1] << ")" << std::endl;

    // Perform linear search in the block
    while (arr[prev] < key)
    {
        std::cout << "Linear searching: " << arr[prev] << std::endl;
        prev++;
        if (prev == std::min(step, N))
        {
            std::cout << "End of interval reached, key not found." << std::endl;
            return -1;
        }
    }

    std::cout << "Key found at index " << prev << ": " << arr[prev] << std::endl;
    if (arr[prev] == key)
    {
        return prev;
    }

    return -1; // Element not found
}

// Function to print a vector
void print_vector(const std::vector<int> &arr)
{
    for (int elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Main function
int main()
{
    // Example 1: Jump Search
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int X = 40;

    std::cout << "Array for jump search: ";
    print_vector(arr);

    int Xi = jumpSearch(arr, X);
    std::cout << "Found number " << X << " at index: " << Xi << std::endl;

    // Example 2: Verbose Jump Search
    std::vector<int> arrVerbose;
    for (int i = 0; i <= 99; i += 3)
    {
        arrVerbose.push_back(i); // Fill vector with multiples of 3 from 0 to 99
    }

    X = 66;
    std::cout << "\nVerbose Jump Search for number " << X << ":" << std::endl;
    print_vector(arrVerbose);
    Xi = jumpSearchVerbose(arrVerbose, X);
    std::cout << "Found number " << X << " at index: " << Xi << std::endl;

    return 0;
}
