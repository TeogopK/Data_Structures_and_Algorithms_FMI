#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSubarray(const std::vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int left = 0;
    int best = 0;

    for (int right = 0; right < nums.size(); ++right)
    {
        int x = nums[right];
        freq[x]++;

        while (freq[x] > k)
        {
            int y = nums[left];
            freq[y]--;
            left++;
        }

        best = max(best, right - left + 1);
    }

    return best;
}