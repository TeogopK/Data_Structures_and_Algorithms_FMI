/*
Bubble Sort Algorithms

1. Time Complexity:
   - Best Case: O(N) when the array is already sorted (for optimized bubble sort with early exit).
   - Average Case: O(N^2) for a random unsorted array.
   - Worst Case: O(N^2) when the array is sorted in reverse order.

2. Space Complexity:
   - O(1) auxiliary space, as bubble sort is an in-place sorting algorithm.

3. Is it Stable?
   - Yes, bubble sort is a stable sorting algorithm. Equal elements maintain their relative positions after sorting.

4. Theoretical Worst-Case Swaps:
   - In the worst case, the number of swaps is N * (N - 1) / 2, where N is the size of the array.
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

// Bubble sort implementation
void bubble_sort(vector<int> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        if (verbose)
        {
            cout << "Start of iteration " << i + 1 << ": ";
            print_vector(arr);
        }
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                if (verbose)
                {
                    print_vector(arr);
                }
            }
        }
        if (verbose)
        {
            cout << "End of iteration " << i + 1 << ".\n";
        }
    }
}

// Optimized Bubble sort (with early exit)
void optimized_bubble_sort(vector<int> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        bool swapped = false;
        if (verbose)
        {
            cout << "Start of iteration " << i + 1 << ": ";
            print_vector(arr);
        }

        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                if (verbose)
                {
                    print_vector(arr);
                }
            }
        }
        if (verbose)
        {
            cout << "End of iteration " << i + 1 << ".\n";
        }

        // Early exit if no elements were swapped
        if (!swapped)
        {
            break;
        }
    }
}

// Worst case bubble sort (Count number of swaps)
void worst_case_bubble_sort(int N)
{
    vector<int> arr(N);
    int swaps = 0;

    // Initialize the array in reverse order
    for (int i = 0; i < N; i++)
    {
        arr[i] = N - i;
    }

    cout << "Initial array: ";
    print_vector(arr);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    cout << "Sorted array: ";
    print_vector(arr);
    cout << "Total swaps: " << swaps << endl;
    cout << "Expected swaps (N * (N - 1) / 2): " << (N * (N - 1)) / 2 << endl;
}

// Stable bubble sort for pairs
void stable_bubble_sort(vector<pair<int, string>> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            // Only compare the integer part of the pair
            if (arr[j].first > arr[j + 1].first)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Stable sorted pairs:\n";
    for (const auto &p : arr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main()
{
    // Standard Bubble Sort
    cout << "Standard Bubble Sort:\n";
    vector<int> arr1 = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    bubble_sort(arr1, true);
    cout << "Final sorted array: ";
    print_vector(arr1);
    cout << endl;

    // Optimized Bubble Sort with early exit
    cout << "Optimized Bubble Sort:\n";
    vector<int> arr2 = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    optimized_bubble_sort(arr2, true);
    cout << "Final sorted array: ";
    print_vector(arr2);
    cout << endl;

    // Worst case scenario for Bubble Sort
    cout << "Worst Case Bubble Sort:\n";
    worst_case_bubble_sort(50);
    cout << endl;

    // Stable Bubble Sort for pairs
    cout << "Stable Bubble Sort for Pairs:\n";
    vector<pair<int, string>> arr3 = {{2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"}};
    stable_bubble_sort(arr3);

    return 0;
}
