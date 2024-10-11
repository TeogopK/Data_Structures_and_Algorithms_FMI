// https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?fbclid=IwZXh0bgNhZW0CMTEAAR2frYNiP2UGW6LLqOUUFL9effg55voQ27W4UXtPogbOiKjiKgMR5o48wK4_aem_Xh4wbNaKuqu2mlx5yXh6fA

// O(n) solution
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int oneDigitNumbersSum = 0;
        int twoDigitNumbersSum = 0;
        int allNumbersSum = 0;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            if(num < 10) {
                oneDigitNumbersSum += num;
            } else if (num < 100) {
                twoDigitNumbersSum += num;
            }

            allNumbersSum += num;
        }

        bool canWinWithOneDigitNumbers = oneDigitNumbersSum > allNumbersSum - oneDigitNumbersSum;
        bool canWinWithTwoDigitNumbers = twoDigitNumbersSum > allNumbersSum - twoDigitNumbersSum;

        return canWinWithOneDigitNumbers || canWinWithTwoDigitNumbers;
    }
};