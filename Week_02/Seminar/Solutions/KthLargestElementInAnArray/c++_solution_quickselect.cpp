class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int next = left;
        for(size_t j = left; j < right; j++) {
            if(nums[j] > pivot) {
                swap(nums[j], nums[next]);
                next++;
            }
        }
        
        swap(nums[right], nums[next]);
        return next;
    }
    
    void partialQuickSort(vector<int>& nums, int left, int right, int k) {
        if (left < right) {
            int partitionIndex = partition(nums, left, right);

            if(partitionIndex == k - 1) {
                return;
            }
            
            if(partitionIndex < k - 1) {
                partialQuickSort(nums, partitionIndex + 1, right, k);
            }
            else {
                partialQuickSort(nums, left, partitionIndex - 1, k);
            }
        }
    }

    // O(n) average time | O(log n) space
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        partialQuickSort(nums, 0, nums.size() - 1, k);
        
        return nums[k - 1];
    }
};
    