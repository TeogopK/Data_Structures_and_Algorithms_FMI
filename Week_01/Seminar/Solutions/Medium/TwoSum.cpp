#include <iostream>
#include <chrono>

// we know that the array is sorted
size_t countPairs(int *arr, size_t count, int target)
{
    size_t result = 0;
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                result++;
            }
        }
    }

    return result;
}

// we know that the array is sorted
size_t countPairsSmart(int *arr, size_t count, int target)
{
    size_t result = 0;

    int leftIndex = 0;
    int rightIndex = count - 1;

    while (leftIndex == rightIndex)
    {
        int sum = arr[leftIndex] + arr[rightIndex];
        if (sum > target)
        {
            rightIndex--;
        }
        else if (sum == target)
        {
            result++;
            leftIndex++;
            rightIndex--;
        }
        else
        {
            leftIndex++;
        }
    }

    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    std::cout << countPairs(arr, 10, 10) << std::endl;
}