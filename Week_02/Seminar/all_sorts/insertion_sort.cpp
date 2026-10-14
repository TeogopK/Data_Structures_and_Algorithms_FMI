/*
Insertion Sort Algorithm

1. Time Complexity:
   - Best Case: O(N) when the array is already sorted.
   - Average Case: O(N^2)
   - Worst Case: O(N^2)

2. Space Complexity:
   - O(1) auxiliary space since insertion sort is an in-place sorting algorithm.

3. Is it Stable?
   - Yes, insertion sort is stable. Equal elements maintain their relative order.

4. Number of Swaps:
   - In the worst case (reverse sorted array), insertion sort performs approximately N * (N - 1) / 2 comparisons and shifts.

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

// Insertion sort implementation
void insertion_sort(vector<int> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i - 1;

        if (verbose)
        {
            cout << "key = " << key << "\n";
            print_vector(arr);
        }

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;

            if (verbose)
            {
                cout << "   ->  ";
                print_vector(arr);
            }
        }
        arr[j + 1] = key;

        if (verbose)
        {
            print_vector(arr);
            cout << "=================\n";
        }
    }
}

// Stable insertion sort for pairs
void stable_insertion_sort(vector<pair<int, string>> &arr, bool verbose = false)
{
    int N = arr.size();

    for (int i = 1; i < N; i++)
    {
        auto key = arr[i];
        int j = i - 1;

        // Compare only the integer part of the pair
        while (j >= 0 && arr[j].first > key.first)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Stable sorted pairs:\n";
    for (const auto &p : arr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>

using namespace std;

// Insertion sort implementation with comparison count (non-verbose)
int insertion_sort_with_comparisons(vector<int> &arr)
{
    int N = arr.size();
    int comparisons = 0; // To keep track of the number of comparisons

    for (int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0)
        {
            comparisons++; // Count each comparison
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break; // No need to compare further if the current element is not greater than the key
            }
        }
        arr[j + 1] = key;
    }

    return comparisons; // Return the total number of comparisons
}

// Insertion sort for worst case scenario with comparison output
void worst_case_insertion_sort(int N)
{
    vector<int> arr(N);

    // Initialize the array in reverse order
    for (int i = 0; i < N; i++)
    {
        arr[i] = N - i;
    }

    print_vector(arr);
    // Apply insertion sort and get the comparison count
    int total_comparisons = insertion_sort_with_comparisons(arr);

    print_vector(arr);
    // Print the total number of comparisons made during sorting
    cout << "Total comparisons in worst case: " << total_comparisons << endl;
}

int main()
{
    // Standard Insertion Sort
    cout << "Standard Insertion Sort:\n";
    vector<int> arr1 = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    insertion_sort(arr1, true);
    cout << "Final sorted array: ";
    print_vector(arr1);
    cout << endl;

    // Worst case scenario for Insertion Sort
    cout << "Worst Case Insertion Sort with Comparisons:\n";
    worst_case_insertion_sort(10); // You can change N here to test different sizes
    cout << endl;

    // Stable Insertion Sort for pairs
    cout << "Stable Insertion Sort for Pairs:\n";
    vector<pair<int, string>> arr2 = {{2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"}};
    stable_insertion_sort(arr2);

    return 0;
}
