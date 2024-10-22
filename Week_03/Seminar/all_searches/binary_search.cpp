#include <iostream>
#include <vector>

// Binary Search Function
int binary_search(const std::vector<int> &arr, int X)
{
    int left = 0;
    int right = arr.size() - 1;
    int Xi = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (X <= arr[mid])
        {
            right = mid - 1;
            Xi = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return Xi;
}

// Leftmost Binary Search Function
int binary_search_leftmost(const std::vector<int> &arr, int X)
{
    int left = 0;
    int right = arr.size() - 1;
    int Xi = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (X <= arr[mid])
        {
            right = mid - 1;
            Xi = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return Xi;
}

// Rightmost Binary Search Function
int binary_search_rightmost(const std::vector<int> &arr, int X)
{
    int left = 0;
    int right = arr.size() - 1;
    int Xi = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (X < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            Xi = mid;
        }
    }

    return Xi;
}

// Recursive Binary Search Function
int binary_search_recursive(const std::vector<int> &arr, int X, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (X == arr[mid])
        {
            return mid;
        }
        else if (X < arr[mid])
        {
            return binary_search_recursive(arr, X, left, mid - 1);
        }
        else
        {
            return binary_search_recursive(arr, X, mid + 1, right);
        }
    }
    return -1; // Element not found
}

// Function to print a vector
void print_vector(const std::vector<int> &arr)
{
    for (const int &elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Main function
int main()
{
    // Binary Search Example
    std::vector<int> arr1 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int X1 = 60;
    int Xi1 = binary_search(arr1, X1);

    print_vector(arr1);
    std::cout << "Found number " << X1 << " at index: " << Xi1 << std::endl;
    std::cout << "----------------------\n";

    // Leftmost Search Example
    std::vector<int> arr2 = {20, 20, 30, 40, 40, 40, 40, 60, 60, 60};
    std::vector<int> targets = {10, 20, 30, 40, 50, 60, 70};

    print_vector(arr2);
    for (int X : targets)
    {
        int Xi2 = binary_search_leftmost(arr2, X);
        std::cout << "Leftmost number " << X << " is at index: " << Xi2 << std::endl;
    }
    std::cout << "----------------------\n";

    // Rightmost Search Example
    print_vector(arr2);
    for (int X : targets)
    {
        int Xi3 = binary_search_rightmost(arr2, X);
        std::cout << "Rightmost number " << X << " is at index: " << Xi3 << std::endl;
    }
    std::cout << "----------------------\n";

    // Recursive Search Example
    int X4 = 40;
    int Xi4 = binary_search_recursive(arr2, X4, 0, arr2.size() - 1);
    print_vector(arr2);
    std::cout << "Number " << X4 << " is at index: " << Xi4 << std::endl;

    return 0;
}
