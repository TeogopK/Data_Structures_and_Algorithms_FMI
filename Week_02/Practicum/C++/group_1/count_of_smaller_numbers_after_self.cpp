// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> counts(n, 0); // result array

        vector<pair<int, int>> arr;

        // Vector of pairs (value, original index)
        for (int i = 0; i < n; ++i)
        {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }

private:
    // Standard merge sort with counts argument to track smaller elements
    void mergeSort(vector<pair<int, int>> &arr, int left, int right, vector<int> &counts)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }

    void merge(vector<pair<int, int>> &arr, int left, int mid, int right, vector<int> &counts)
    {
        // Create two temporary arrays
        vector<pair<int, int>> left_part(arr.begin() + left, arr.begin() + mid + 1);
        vector<pair<int, int>> right_part(arr.begin() + mid + 1, arr.begin() + right + 1);

        int l = 0;    // index for left array
        int r = 0;    // index for right array
        int k = left; // index for merged array

        int rightCount = 0; // how many elements from the right have been smaller

        // The core is to count inversions during a modified merge sort.
        // When merging two sorted halves, we can count how many elements from the right half are placed
        // before elements from the left half. This count indicates how many smaller elements are to
        // the right of each element in the original array.
        while (l < left_part.size() && r < right_part.size())
        {
            if (left_part[l].first <= right_part[r].first)
            {
                // For the current element from the left half
                // we have already seen 'rightCount' smaller elements from the right
                counts[left_part[l].second] += rightCount;
                arr[k++] = left_part[l++];
            }
            else
            {
                // The element from the right is smaller → it will appear before left_part[l]
                rightCount++;
                arr[k++] = right_part[r++];
            }
        }

        // If there are remaining elements in the left half
        while (l < left_part.size())
        {
            counts[left_part[l].second] += rightCount;
            arr[k++] = left_part[l++];
        }

        // If there are remaining elements in the right half
        while (r < right_part.size())
        {
            arr[k++] = right_part[r++];
        }
    }
};
