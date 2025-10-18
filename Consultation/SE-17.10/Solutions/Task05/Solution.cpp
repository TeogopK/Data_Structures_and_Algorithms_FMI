#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// The time complexity is linear but it will still be slower than counting by a constant multiplier
// Time complexity: O(n)
// Space complexity: O(1)
int partition(std::vector<int>& arr, int element, int left = 0)
{
    int right = arr.size() - 1;

    while (left < right)
    {
        while (std::abs(arr[left]) <= element)
        {
            left++;
            if (left == right) { break; }
        }

        while (std::abs(arr[right]) > element)
        {
            right--;
            if (left == right) { break; }
        }

        if (left >= right) { break; }

        std::swap(arr[left], arr[right]);
    }

    return left;
}

void rearrangeByAbsPartition(std::vector<int>& arr)
{
    int begin = 0;
    for (int num = 0; num <= 100; ++num)
    {
        begin = partition(arr, num, begin);
    }
}

// The solution uses extra memory (based on the domain of values)
// Linear solution but faster by a constant multiplier
// Time complexity: O(n + d)
// Space complexity: O(d)
void rearrangeByAbsCounting(std::vector<int>& arr)
{
    std::vector<int> positive(101);
    std::vector<int> negative(101);

    for (int num : arr) {
        if (num > 0) {
            positive[num]++;
        }
        else {
            negative[-num]++;
        }
    }

    size_t index = 0;
    for (size_t i = 0; i < negative[0]; i++)
    {
        arr[index++] = 0;
    }
    for (int abs_value = 1; abs_value <= 100; ++abs_value) {
        for (int i = 0; i < positive[abs_value]; i++) {
            arr[index++] = abs_value;
        }
        for (int i = 0; i < negative[abs_value]; i++) {
            arr[index++] = -abs_value;
        }
    }
}

void printVector(const std::vector<int>& arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    {
        std::vector<int> arr = { -1, 5, 3, 4, 1, -3, -4, -5, 1 };
        rearrangeByAbsPartition(arr);
        printVector(arr); // -1 1 1 -3 3 4 -4 -5 5
    }
    {
        std::vector<int> arr = { -1, 5, 3, 4, 1, -3, -4, -5, 1 };
        rearrangeByAbsCounting(arr);
        printVector(arr); // 1 1 -1 3 -3 4 -4 5 -5
    }
}