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
void merge(vector<int> &arr, vector<int> &left_arr, vector<int> &right_arr)
{
    cout << "Start of merging <- ";
    cout << "Left: ";
    for (int n : left_arr)
        cout << n << " ";
    cout << "| Right: ";
    for (int n : right_arr)
        cout << n << " ";
    cout << endl;

    int index = 0, left = 0, right = 0;
    int left_size = left_arr.size();
    int right_size = right_arr.size();

    while (left < left_size && right < right_size)
    {
        if (left_arr[left] <= right_arr[right])
        {
            arr[index] = left_arr[left];
            left++;
        }
        else
        {
            arr[index] = right_arr[right];
            right++;
        }
        index++;
    }

    while (left < left_size)
    {
        arr[index] = left_arr[left];
        left++;
        index++;
    }

    while (right < right_size)
    {
        arr[index] = right_arr[right];
        right++;
        index++;
    }

    cout << "End of merging: ";
    for (int n : arr)
        cout << n << " ";
    cout << endl;
}

// Merge sort implementation for integers with verbose output
void merge_sort(vector<int> &arr)
{
    if (arr.size() > 1)
    {
        int middle = arr.size() / 2;

        vector<int> left_arr(arr.begin(), arr.begin() + middle);
        vector<int> right_arr(arr.begin() + middle, arr.end());

        cout << "Splitting: ";
        for (int n : arr)
            cout << n << " ";
        cout << "-> Left: ";
        for (int n : left_arr)
            cout << n << " ";
        cout << "| Right: ";
        for (int n : right_arr)
            cout << n << " ";
        cout << endl;

        merge_sort(left_arr);
        merge_sort(right_arr);

        merge(arr, left_arr, right_arr);
    }
}

// Function to merge two halves for pairs
void merge_pairs(vector<pair<int, string>> &arr, vector<pair<int, string>> &left_arr, vector<pair<int, string>> &right_arr)
{
    int index = 0, left = 0, right = 0;
    int left_size = left_arr.size();
    int right_size = right_arr.size();

    while (left < left_size && right < right_size)
    {
        if (left_arr[left].first <= right_arr[right].first)
        {
            arr[index] = left_arr[left];
            left++;
        }
        else
        {
            arr[index] = right_arr[right];
            right++;
        }
        index++;
    }

    while (left < left_size)
    {
        arr[index] = left_arr[left];
        left++;
        index++;
    }

    while (right < right_size)
    {
        arr[index] = right_arr[right];
        right++;
        index++;
    }
}

// Merge sort implementation for pairs
void merge_sort_pairs(vector<pair<int, string>> &arr)
{
    if (arr.size() > 1)
    {
        int middle = arr.size() / 2;

        vector<pair<int, string>> left_arr(arr.begin(), arr.begin() + middle);
        vector<pair<int, string>> right_arr(arr.begin() + middle, arr.end());

        merge_sort_pairs(left_arr);
        merge_sort_pairs(right_arr);

        merge_pairs(arr, left_arr, right_arr);
    }
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
