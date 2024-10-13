/*
Quick Sort Algorithm

1. Time Complexity:
   - Average Case: O(N log N) for a random unsorted array.
   - Worst Case: O(N^2) when the array is sorted in reverse order or all elements are the same.

2. Space Complexity:
   - O(log N) auxiliary space for the call stack in the recursive implementation.

3. Is it Stable?
   - No, quick sort is not a stable sorting algorithm. Equal elements may not maintain their relative positions after sorting.

4. Divide and Conquer principle:
   - Quick sort works by selecting a pivot and partitioning the array around that pivot, recursively sorting the left and right subarrays.
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to print a vector
template <typename T>
void print_vector(const vector<T> &arr)
{
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}

// Function to partition the array around a pivot
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low;           // Index of the smaller element

    cout << "New pivot number: " << pivot << ", low: " << low << ", high: " << high << endl;
    cout << "Before: ";
    print_vector(vector<int>(arr.begin() + low, arr.begin() + high + 1)); // Print the subarray

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]); // Swap elements
            i++;                  // Increment the index of smaller element
        }
    }

    swap(arr[i], arr[high]); // Place the pivot in the correct position

    cout << "After: ";
    print_vector(vector<int>(arr.begin() + low, arr.begin() + high + 1)); // Print the subarray after partition
    return i;                                                             // Return the partitioning index
}

// Function implementing quick sort
void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_pairs(const vector<pair<int, string>> &arr)
{
    for (const auto &p : arr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

// Function to partition the array of pairs
int partition(vector<pair<int, string>> &arr, int low, int high)
{
    int pivot = arr[high].first; // Choosing the first element of the pair as the pivot
    int i = low;                 // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j].first <= pivot)
        {                         // Comparing the integer part of the pairs
            swap(arr[i], arr[j]); // Swap elements
            i++;                  // Increment the index of smaller element
        }
    }

    swap(arr[i], arr[high]); // Place the pivot in the correct position
    return i;                // Return the partitioning index
}

// Function implementing quick sort for pairs
void quick_sort(vector<pair<int, string>> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void test_basic_quick_sort()
{
    // Example array to sort
    vector<int> arr = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    int N = arr.size();

    cout << "Initial array: ";
    print_vector(arr);

    // Call quick sort
    quick_sort(arr, 0, N - 1);

    // Print the final sorted array
    cout << "Sorted array: ";
    print_vector(arr);
    cout << endl;
}

void test_pairs_quick_sort()
{
    // Example array of pairs to sort
    vector<pair<int, string>> arr = {{2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"}};
    int N = arr.size();

    cout << "Initial array of pairs: ";
    print_pairs(arr);

    // Call quick sort on the array of pairs
    quick_sort(arr, 0, N - 1);

    // Print the final sorted array of pairs
    cout << "Sorted array of pairs: ";
    print_pairs(arr);
    cout << endl;
}

int main()
{
    test_basic_quick_sort();
    std::cout << endl;
    test_pairs_quick_sort();

    return 0;
}