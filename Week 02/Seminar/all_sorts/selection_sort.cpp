/*
Selection Sort Algorithms

1. Time Complexity:
   - Best Case: O(N^2)
   - Average Case: O(N^2)
   - Worst Case: O(N^2)

2. Space Complexity:
   - O(1) auxiliary space, as selection sort is an in-place sorting algorithm.

3. Is it Stable?
   - No, selection sort is not stable. It swaps non-adjacent elements, which can change the relative order of equal elements.

4. Number of Swaps:
   - Always performs N - 1 swaps, unless we avoid unnecessary swaps when the minimum element is already in the correct position.
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

// Selection sort implementation
void selection_sort(vector<int> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        int min_index = i;

        if (verbose)
        {
            cout << "Start of " << i + 1 << " iteration: ";
            print_vector(arr);
        }

        // Find the minimum element in the remaining unsorted part of the array
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }

        if (verbose)
        {
            std::cout << "min_index = " << min_index << " ------> ";
            print_vector(arr);
            std::cout << "=================\n";
        }
    }
}

// Worst case scenario for Selection Sort
void worst_case_selection_sort(int N)
{
    vector<int> arr(N);
    int swaps = 0;

    // Initialize the array with [N, 1, 2, ..., N-1]
    arr[0] = N;
    for (int i = 1; i < N; i++)
    {
        arr[i] = i;
    }

    cout << "Initial array: ";
    print_vector(arr);

    for (int i = 0; i < N - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
            swaps++;
        }
    }

    cout << "Sorted array: ";
    print_vector(arr);
    cout << "Total swaps: " << swaps << endl;
    cout << "Expected swaps: " << N - 1 << endl;
}

// Selection sort for pairs (not stable)
void selection_sort_pairs(vector<pair<int, string>> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < N; j++)
        {
            // Compare only the integer part of the pair
            if (arr[j].first < arr[min_index].first)
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }

    cout << "Sorted pairs:\n";
    for (const auto &p : arr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main()
{
    // Standard Selection Sort
    cout << "Standard Selection Sort:\n";
    vector<int> arr1 = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    selection_sort(arr1, true);
    cout << "Final sorted array: ";
    print_vector(arr1);
    cout << endl;

    // Worst case scenario for Selection Sort
    cout << "Worst Case Selection Sort:\n";
    worst_case_selection_sort(10);
    cout << endl;

    // Selection Sort for pairs (not stable)
    cout << "Selection Sort for Pairs:\n";
    vector<pair<int, string>> arr2 = {{2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"}};
    selection_sort_pairs(arr2);

    return 0;
}
