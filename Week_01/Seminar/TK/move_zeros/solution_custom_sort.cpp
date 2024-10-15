#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool compareZero(const int &left, const int &right)
    {
        return left != 0 && right == 0;
    }

    void moveZeroes(vector<int> &nums)
    {
        std::stable_sort(nums.begin(), nums.end(), compareZero);
    }
};