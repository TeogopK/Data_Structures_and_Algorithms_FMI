/*
Merge Sort Algorithm

1. Time Complexity:
   - Best Case: O(NlogN)
   - Average Case: O(NlogN)
   - Worst Case: O(NlogN)

2. Space Complexity:
   - O(N) auxiliary space due to the extra arrays created during merging.

3. Is it Stable?
   - Yes, merge sort is stable if implemented carefully. It preserves the relative order of equal elements.

4. Divide and Conquer principle:
   - Merge sort works by splitting the array in halves recursively and merging them back together in sorted order.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to merge two halves for integers with verbose output
void merge(vector<int> &arr, vector<int> &temp, int left_start, int right_start, int right_end)
{
    int left = left_start;
    int left_end = right_start - 1;
    int index = left_start;
    int right = right_start;

    cout << "Start of merging <- ";
    cout << "Left: ";
    for (int i = left_start; i <= left_end; i++)
        cout << arr[i] << " ";
    cout << "| Right: ";
    for (int i = right_start; i <= right_end; i++)
        cout << arr[i] << " ";
    cout << endl;

    while (left <= left_end && right <= right_end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index++] = arr[left++];
        }
        else
        {
            temp[index++] = arr[right++];
        }
    }

    while (left <= left_end)
    {
        temp[index++] = arr[left++];
    }

    while (right <= right_end)
    {
        temp[index++] = arr[right++];
    }

    for (int i = left_start; i <= right_end; i++)
    {
        arr[i] = temp[i];
    }

    cout << "End of merging: ";
    for (int i = left_start; i <= right_end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Merge sort implementation for integers with buffer
void merge_sort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start < end)
    {
        // Avoids overflow for large values of start and end, equal to (start + end) / 2
        int middle = start + (end - start) / 2;

        merge_sort(arr, temp, start, middle);
        merge_sort(arr, temp, middle + 1, end);

        merge(arr, temp, start, middle + 1, end);
    }
}

void merge_sort(vector<int> &arr)
{
    vector<int> temp(arr.size());
    merge_sort(arr, temp, 0, arr.size() - 1);
}

// Function to merge two halves for pairs
void merge_pairs(vector<pair<int, string>> &arr, vector<pair<int, string>> &temp, int left_start, int right_start, int right_end)
{
    int left = left_start;
    int left_end = right_start - 1;
    int index = left_start;
    int right = right_start;

    while (left <= left_end && right <= right_end)
    {
        if (arr[left].first <= arr[right].first)
        {
            temp[index++] = arr[left++];
        }
        else
        {
            temp[index++] = arr[right++];
        }
    }

    while (left <= left_end)
    {
        temp[index++] = arr[left++];
    }

    while (right <= right_end)
    {
        temp[index++] = arr[right++];
    }

    for (int i = left_start; i <= right_end; i++)
    {
        arr[i] = temp[i];
    }
}

// Merge sort implementation for pairs with buffer
void merge_sort_pairs(vector<pair<int, string>> &arr, vector<pair<int, string>> &temp, int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;

        merge_sort_pairs(arr, temp, start, middle);
        merge_sort_pairs(arr, temp, middle + 1, end);

        merge_pairs(arr, temp, start, middle + 1, end);
    }
}

void merge_sort_pairs(vector<pair<int, string>> &arr)
{
    vector<pair<int, string>> temp(arr.size());
    merge_sort_pairs(arr, temp, 0, arr.size() - 1);
}

// Main function for integer merge sort
void test_merge_sort_integers()
{
    cout << "Merge Sort for Integers:\n";
    vector<int> arr = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    merge_sort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function for pairs merge sort
void test_merge_sort_pairs()
{
    cout << "Merge Sort for Pairs:\n";
    vector<pair<int, string>> arr = {{2, "woman"}, {1, "a"}, {1, "b"}, {2, "man"}, {1, "c"}};
    merge_sort_pairs(arr);

    cout << "Sorted pairs: ";
    for (const auto &p : arr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main()
{
    // Test merge sort for integers
    test_merge_sort_integers();

    cout << endl;

    // Test merge sort for pairs
    test_merge_sort_pairs();

    return 0;
}
