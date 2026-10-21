// Jump search on last column
// Then linear in the row

#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int N = matrix.size();
        int M = matrix[0].size();

        int i = 0;
        while (i < N && target > matrix[i][M - 1])
        {
            i++;
        }

        if (i == N)
        {
            return false;
        }

        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }

        return false;
    }
};
