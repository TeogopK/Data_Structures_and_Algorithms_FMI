// Binary on the last column
// Then binary on the row

#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;

        int Mi = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (target <= matrix[mid].back())
            {
                right = mid - 1;
                Mi = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (Mi == -1)
        {
            return false;
        }

        left = 0;
        right = matrix[Mi].size() - 1;

        int Xi = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (target <= matrix[Mi][mid])
            {
                right = mid - 1;
                Xi = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return matrix[Mi][Xi] == target;
    }
};
