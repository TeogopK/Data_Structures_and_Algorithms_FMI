#include <iostream>
#include <vector>

// Function to print a vector
void print_vector(const std::vector<int> &arr, const int start, const int right)
{
    for (int i = start; i <= right; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Ternary Search Function
int ternarySearch(const std::vector<int> &arr, int key, int l, int r)
{
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key)
        {
            return mid1;
        }
        if (arr[mid2] == key)
        {
            return mid2;
        }

        if (key < arr[mid1])
        {
            return ternarySearch(arr, key, l, mid1 - 1);
        }
        else if (key > arr[mid2])
        {
            return ternarySearch(arr, key, mid2 + 1, r);
        }
        else
        {
            return ternarySearch(arr, key, mid1 + 1, mid2 - 1);
        }
    }
    return -1; // Element not found
}

// Verbose Ternary Search Function
int ternarySearchVerbose(const std::vector<int> &arr, int key, int l, int r)
{
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        std::cout << "arr[mid1=" << mid1 << "] = " << arr[mid1] << ", arr[mid2=" << mid2 << "] = " << arr[mid2] << std::endl;
        print_vector(arr, l, r);

        if (arr[mid1] == key)
        {
            return mid1;
        }
        if (arr[mid2] == key)
        {
            return mid2;
        }

        if (key < arr[mid1])
        {
            return ternarySearchVerbose(arr, key, l, mid1 - 1);
        }
        else if (key > arr[mid2])
        {
            return ternarySearchVerbose(arr, key, mid2 + 1, r);
        }
        else
        {
            return ternarySearchVerbose(arr, key, mid1 + 1, mid2 - 1);
        }
    }
    return -1; // Element not found
}

// Main function
int main()
{
    // Ternary Search Example
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int X = 60;

    std::cout << "Array for ternary search: ";
    print_vector(arr, 0, arr.size() - 1);
    int Xi = ternarySearch(arr, X, 0, arr.size() - 1);
    std::cout << "Number " << X << " is at index: " << Xi << std::endl;

    // Verbose Version Example
    std::vector<int> arrVerbose(100);
    for (int i = 0; i < 100; ++i)
    {
        arrVerbose[i] = i; // Fill the vector with numbers from 0 to 99
    }

    X = 60;
    std::cout << "\nArray for verbose ternary search: ";
    print_vector(arrVerbose, 0, arrVerbose.size() - 1);
    Xi = ternarySearchVerbose(arrVerbose, X, 0, arrVerbose.size() - 1);
    std::cout << "Number " << X << " is at index: " << Xi << std::endl;

    return 0;
}
