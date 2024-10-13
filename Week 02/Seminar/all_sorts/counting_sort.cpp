/*
Counting Sort Algorithm

1. Time Complexity:
   - Best Case: O(N + K)
   - Average Case: O(N + K)
   - Worst Case: O(N + K)
   - N = number of elements in the input array
   - K = range of input values (difference between maximum and minimum values)

2. Space Complexity:
   - O(N + K) auxiliary space, where we use additional space for the count and output arrays.

3. Is it Stable?
   - Yes, counting sort is stable. Elements with the same value retain their relative order after sorting.

4. When to Use:
   - Counting sort is useful when the range of input values is not significantly larger than the number of elements (K is close to N).
   - Not suitable for data with a very large range of values (K is much larger than N).
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max

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

// Counting sort for non-negative values
void counting_sort(vector<int> &arr)
{
    int N = arr.size();
    if (N == 0)
        return;

    int K = *max_element(arr.begin(), arr.end()) + 1;

    vector<int> output(N);
    vector<int> count(K, 0);

    // Step 1: Count occurrences of each value
    for (int i = 0; i < N; i++)
    {
        count[arr[i]]++;
    }

    // Step 2: Update count array to store the cumulative counts
    for (int i = 1; i < K; i++)
    {
        count[i] += count[i - 1];
    }

    // Step 3: Place the elements in the correct order in the output array
    for (int i = N - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 4: Copy sorted values back to original array
    for (int i = 0; i < N; i++)
    {
        arr[i] = output[i];
    }
}

// Counting sort for arrays with negative values
void counting_sort_with_negatives(vector<int> &arr)
{
    int N = arr.size();
    if (N == 0)
        return;

    int max_value = *max_element(arr.begin(), arr.end());
    int min_value = *min_element(arr.begin(), arr.end());
    int K = max_value - min_value + 1;

    vector<int> output(N);
    vector<int> count(K, 0);

    // Step 1: Count occurrences of each value (adjust for negative values)
    for (int i = 0; i < N; i++)
    {
        count[arr[i] - min_value]++;
    }

    // Step 2: Update count array to store the cumulative counts
    for (int i = 1; i < K; i++)
    {
        count[i] += count[i - 1];
    }

    // Step 3: Place the elements in the correct order in the output array
    for (int i = N - 1; i >= 0; i--)
    {
        output[count[arr[i] - min_value] - 1] = arr[i];
        count[arr[i] - min_value]--;
    }

    // Step 4: Copy sorted values back to original array
    for (int i = 0; i < N; i++)
    {
        arr[i] = output[i];
    }
}

// Function to print a vector of pairs
void print_vector_of_pairs(const vector<pair<int, string>> &arr)
{
    for (const auto &elem : arr)
    {
        cout << "(" << elem.first << ", " << elem.second << ") ";
    }
    cout << endl;
}

// Counting sort for a vector of pairs (stable sort)
void counting_sort_pairs(vector<pair<int, string>> &arr)
{
    int N = arr.size();
    if (N == 0)
        return;

    int K = (*max_element(arr.begin(), arr.end(), [](const pair<int, string> &a, const pair<int, string> &b)
                          { return a.first < b.first; }))
                .first +
            1;

    vector<pair<int, string>> output(N);
    vector<int> count(K, 0);

    // Step 1: Count occurrences of each integer key (first element of the pair)
    for (int i = 0; i < N; i++)
    {
        count[arr[i].first]++;
    }

    // Step 2: Update count array to store cumulative counts
    for (int i = 1; i < K; i++)
    {
        count[i] += count[i - 1];
    }

    // Step 3: Build the output array in reverse order to maintain stability
    for (int i = N - 1; i >= 0; i--)
    {
        output[count[arr[i].first] - 1] = arr[i];
        count[arr[i].first]--;
    }

    // Step 4: Copy sorted values back to original array
    for (int i = 0; i < N; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    // Standard counting sort for non-negative values
    cout << "Standard Counting Sort:\n";
    vector<int> arr1 = {9, 4, 3, 2, 6, 7, 1, 8, 5};
    counting_sort(arr1);
    cout << "Sorted array: ";
    print_vector(arr1);
    cout << endl;

    // Counting sort for an array with negative values
    cout << "Counting Sort with Negative Values:\n";
    vector<int> arr2 = {0, 4, -3, -2, 1, 2, -1, 6, 5};
    counting_sort_with_negatives(arr2);
    cout << "Sorted array: ";
    print_vector(arr2);
    cout << endl;

    // Example with stable sorting for pairs
    cout << "Stable Counting Sort for Pairs:\n";
    vector<pair<int, string>> arr = {{6, "Bella"}, {5, "Bailey"}, {6, "Charlie"}, {6, "Daisy"}, {5, "Luna"}};
    counting_sort_pairs(arr);
    cout << "Sorted pairs: ";
    print_vector_of_pairs(arr);

    return 0;
}
