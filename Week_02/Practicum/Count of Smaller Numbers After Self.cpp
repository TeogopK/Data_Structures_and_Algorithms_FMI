class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int, int>> p;
        vector<int> counts(size, 0);

        for (int i = 0; i < size; i++) {
            p.push_back({nums[i], i});
        }

        mergeSortAndCount(p, counts, 0, size - 1);

        return counts;
    }

    void mergeAndCount(vector<pair<int, int>>& arr, vector<int>& counts, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int leftIndex = left;
        int rightIndex = mid + 1;
        int currentIndex = 0;
        
        int rightCount = 0; 
        
        while (leftIndex <= mid && rightIndex <= right) {
            if (arr[leftIndex].first <= arr[rightIndex].first) {
                counts[arr[leftIndex].second] += rightCount; 
                temp[currentIndex++] = arr[leftIndex++];
            } else {
                rightCount++;
                temp[currentIndex++] = arr[rightIndex++];
            }
        }

        while (leftIndex <= mid) {
            counts[arr[leftIndex].second] += rightCount;
            temp[currentIndex++] = arr[leftIndex++];
        }

        while (rightIndex <= right) {
            temp[currentIndex++] = arr[rightIndex++];
        }

        for (int i = 0; i < temp.size(); i++) {
            arr[left + i] = temp[i];
        }
    }

    void mergeSortAndCount(vector<pair<int, int>>& arr, vector<int>& counts, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSortAndCount(arr, counts, left, mid);      
        mergeSortAndCount(arr, counts, mid + 1, right);  
        mergeAndCount(arr, counts, left, mid, right);   
    }
};
