// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?fbclid=IwZXh0bgNhZW0CMTEAAR0gzMh_YHR0BpMHEfojkn83mKjjKDaBdkAAnz3B4CEb1_9It3Alsq8DBus_aem_-T_-RK2zI0rxH5r-7Do0sA

// O(nlogn) solution
/* Logic:
 *  Sort the array.
 *  For each number in the array, we need to check if the number is the same as the previous number.
 *  If it is, we add it to the next row.
 *  If it isn't, we reset the current number and add it to the first row.
 */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> arr2D;

        sort(nums.begin(), nums.end());

        int currentNumber = -1;
        int currentNumberCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (currentNumber == num){
                currentNumberCount ++;
            } else {
                currentNumber = num;
                currentNumberCount = 0;
            }

            // We need to initialize the vector for the current number if it doesn't exist.
            if(arr2D.size() < currentNumberCount + 1){
                arr2D.push_back(vector<int>());
            }

            arr2D[currentNumberCount].push_back(num);
        }

        return arr2D;
    }
};