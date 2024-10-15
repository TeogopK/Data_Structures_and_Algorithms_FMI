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

// Standard Bubble Sort (with comparison and swap count)
void bubble_sort(vector<int> &arr, int &compCount, int &swapCount)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            compCount++; // Increment comparison count
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++; // Increment swap count
            }
        }
    }
}

// Optimized Bubble Sort (with early exit, comparison, and swap count)
void optimized_bubble_sort(vector<int> &arr, int &compCount, int &swapCount)
{
    int N = arr.size();

    for (int i = 0; i < N - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < N - 1 - i; j++)
        {
            compCount++; // Increment comparison count
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++; // Increment swap count
                swapped = true;
            }
        }

        // Early exit if no elements were swapped
        if (!swapped)
        {
            break;
        }
    }
}

// Even more optimized Bubble Sort (with reduced iterations and counting comparisons and swaps)
void evenMoreOptimizedBubbleSort(vector<int> &arr, int &compCount, int &swapCount)
{
    int lastSwappedIndex = arr.size() - 1; // Initialize to the end of the array

    for (size_t i = 0; i < arr.size(); i++)
    {
        int currentSwappedIndex = -1; // Track the most recent swap index

        for (size_t j = 0; j < lastSwappedIndex; j++)
        {
            compCount++; // Increment comparison count
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;             // Increment swap count
                currentSwappedIndex = j; // Update swap index
            }
        }

        // If no swaps happened, the array is already sorted
        if (currentSwappedIndex == -1)
        {
            break;
        }

        // Update the last swapped position to minimize future comparisons
        lastSwappedIndex = currentSwappedIndex;
    }
}

int main()
{
    // Test array
    vector<int> arr1 = {9, 15, 25, 4, 3, 2, 6, 7, 1, 8, 5, 10, 20};

    // Comparison and swap counts for each sort
    int compCount1 = 0, swapCount1 = 0;
    int compCount2 = 0, swapCount2 = 0;
    int compCount3 = 0, swapCount3 = 0;

    // Standard Bubble Sort
    vector<int> arrCopy1 = arr1; // Copy for each sort
    cout << "Standard Bubble Sort:\n";
    bubble_sort(arrCopy1, compCount1, swapCount1);
    print_vector(arrCopy1);
    cout << "Comparisons: " << compCount1 << ", Swaps: " << swapCount1 << "\n\n";

    // Optimized Bubble Sort
    vector<int> arrCopy2 = arr1;
    cout << "Optimized Bubble Sort:\n";
    optimized_bubble_sort(arrCopy2, compCount2, swapCount2);
    print_vector(arrCopy2);
    cout << "Comparisons: " << compCount2 << ", Swaps: " << swapCount2 << "\n\n";

    // Even more optimized Bubble Sort
    vector<int> arrCopy3 = arr1;
    cout << "Even More Optimized Bubble Sort:\n";
    evenMoreOptimizedBubbleSort(arrCopy3, compCount3, swapCount3);
    print_vector(arrCopy3);
    cout << "Comparisons: " << compCount3 << ", Swaps: " << swapCount3 << "\n\n";

    return 0;
}
