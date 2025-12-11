#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        std::priority_queue<int> pq;

        for (int el : nums)
        {
            pq.push(el);
        }

        for (int i = 1; i < k; i++)
        {
            pq.pop();
        }

        return pq.top();
    }
};