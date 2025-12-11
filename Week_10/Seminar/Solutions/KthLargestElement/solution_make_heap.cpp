#include <algorithm> // for heap
#include <vector>

using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        std::make_heap(nums.begin(), nums.end());

        for (int i = 1; i < k; i++)
        {
            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back(); // the element is not deleted only moved to the end of the vector
        }

        return nums.front();
    }
};