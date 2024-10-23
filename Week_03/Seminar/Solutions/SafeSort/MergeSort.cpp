#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comparator_concat(const string &left, const string &right)
{
    return left + right > right + left;
}

void _merge(std::vector<string> &arr, size_t left, size_t mid, size_t right, std::vector<string> &buffer)
{
    size_t leftIdx = left;
    size_t rightIdx = mid;
    size_t index = 0;

    while (leftIdx < mid && rightIdx < right)
    {
        if (comparator_concat(arr[leftIdx], arr[rightIdx])) // The only different part
        {
            buffer[index++] = arr[leftIdx++];
        }
        else
        {
            buffer[index++] = arr[rightIdx++];
        }
    }

    while (leftIdx < mid)
    {
        buffer[index++] = arr[leftIdx++];
    }

    while (rightIdx < right)
    {
        buffer[index++] = arr[rightIdx++];
    }

    for (size_t i = 0; i < index; i++)
    {
        arr[left + i] = buffer[i];
    }
}

void _mergeSort(std::vector<string> &arr, size_t left, size_t right, std::vector<string> &buffer)
{
    if (right - left <= 1)
    {
        return;
    }

    size_t mid = left + (right - left) / 2;

    _mergeSort(arr, left, mid, buffer);
    _mergeSort(arr, mid, right, buffer);
    _merge(arr, left, mid, right, buffer);
}

void mergeSort(std::vector<string> &arr)
{
    if (arr.size() <= 1)
    {
        return;
    }

    std::vector<string> buffer(arr.size());
    _mergeSort(arr, 0, arr.size(), buffer);
}

int main()
{
    int N;
    cin >> N;

    vector<string> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    // If the array has only zeros, the result is 0
    if (count(arr.begin(), arr.end(), "0") == N)
    {
        cout << 0 << endl;
        return 0;
    }

    // Else sort the vector by which concatenation is bigger via own sort
    mergeSort(arr);

    for (const string &s : arr)
    {
        cout << s;
    }

    cout << endl;
    return 0;
}
