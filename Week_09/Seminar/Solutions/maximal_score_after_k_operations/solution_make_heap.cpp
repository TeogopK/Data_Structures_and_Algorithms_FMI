#include <algorithm> // for heap
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        std::make_heap(nums.begin(), nums.end());

        long long current, total = 0;
        while (k--)
        {
            current = nums.front();
            total += current;

            std::pop_heap(nums.begin(), nums.end());

            current = ceil(current / 3.0);
            nums[nums.size() - 1] = current;

            std::push_heap(nums.begin(), nums.end());
        }
        return total;
    }
};