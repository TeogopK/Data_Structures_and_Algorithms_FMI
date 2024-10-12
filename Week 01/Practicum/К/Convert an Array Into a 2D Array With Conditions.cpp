// Наблюдението, което помага за решението на задачата, е, 
// че едно число ще се среща в толкова на брой редове в матрицата,
// колкото са на брой срещанията му във вектора nums. 

// Например в [1,3,4,1,2,3,1] 1-цата се среща 3 пъти, т.е. ще бъде в 3 реда от матрицата
// Така се съобразява и че броят на редовете на матрицата е броят срещания на числото, повтарящо се най-много пъти.
class Solution {
    int indices[201] {}; // на позиция i в масива пазим броя останали i-ки, които трябва да сложим в матрицата
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int rows = 0, idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            rows = max(rows, ++indices[nums[i]]);
        }

        vector<vector<int>> matrix(rows);
        for (int i = 0; i < nums.size(); ++i) {
            matrix[--indices[nums[i]]].push_back(nums[i]);
        }

        return matrix;
    }
};