class Solution {
public:
    int partition(vector<string>& nums, int from, int to) {
        int initialPivotIndex = rand() % (to - from + 1) + from;
        swap(nums[initialPivotIndex], nums[to]);
        int newIdx = from;
        for(size_t i = from; i < to; i++) {
            if(nums[i].size() > nums[to].size() || (nums[i].size() == nums[to].size() && nums[i] > nums[to])) {
                swap(nums[i], nums[newIdx]);
                newIdx++;
            }
        }
        swap(nums[to], nums[newIdx]);
        return newIdx;
    }
    void qSelect(vector<string>& nums, int from, int to, int k) {
        int partitionIndex = partition(nums, from, to);
        if(partitionIndex == k - 1) {
            return;
        }
        
        if(partitionIndex > k - 1) {
            qSelect(nums, from, partitionIndex - 1, k);
        }
        else {
            qSelect(nums, partitionIndex + 1, to, k);
        }
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        srand(time(0));
        qSelect(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};
