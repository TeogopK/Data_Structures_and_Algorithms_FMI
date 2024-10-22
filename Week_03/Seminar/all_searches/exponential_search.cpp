#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Recursive Binary Search Function
int binarySearchRecursive(const std::vector<int> &arr, int key, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearchRecursive(arr, key, left, mid - 1);
        }
        else
        {
            return binarySearchRecursive(arr, key, mid + 1, right);
        }
    }
    return -1; // Element not found
}

// Exponential Search Function
int exponentialSearch(const std::vector<int> &arr, int key)
{
    int N = arr.size();
    if (arr[0] == key)
    {
        return 0;
    }

    // Find range for binary search
    int i = 1;
    while (i < N && arr[i] <= key)
    {
        i = i * 2;
    }

    // Call binary search for the found range
    return binarySearchRecursive(arr, key, i / 2, std::min(i, N - 1));
}

// Verbose Exponential Search Function
int exponentialSearchVerbose(const std::vector<int> &arr, int key)
{
    int N = arr.size();
    if (arr[0] == key)
    {
        std::cout << "Key found at index 0" << std::endl;
        return 0;
    }

    int i = 1;
    while (i < N && arr[i] <= key)
    {
        std::cout << "i = " << i << ", arr[" << i << "] = " << arr[i] << std::endl;
        i = i * 2;
    }

    int left = i / 2;
    int right = std::min(i, N - 1);
    std::cout << "Number is between indexes " << left << " and " << right << std::endl;
    std::cout << "Number is between: " << arr[left] << " and " << arr[right] << std::endl;
    std::cout << "Binary searching..." << std::endl;

    return binarySearchRecursive(arr, key, left, right);
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
    // Example 1: Exponential Search
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int X = 60;

    std::cout << "Array for exponential search: ";
    print_vector(arr);

    int Xi = exponentialSearch(arr, X);
    std::cout << "Number " << X << " is at index: " << Xi << std::endl;

    // Example 2: Verbose Exponential Search
    std::vector<int> arrVerbose;
    for (int i = 0; i <= 95; i += 5)
    {
        arrVerbose.push_back(i); // Fill vector with multiples of 5 from 0 to 95
    }

    X = 60;
    std::cout << "\nVerbose Exponential Search for number " << X << ":" << std::endl;
    print_vector(arrVerbose);
    Xi = exponentialSearchVerbose(arrVerbose, X);
    std::cout << "Number " << X << " is at index: " << Xi << std::endl;

    return 0;
}
