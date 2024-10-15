#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size();

        // Transposing the matrix
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reversing each row
        for (int i = 0; i < N; ++i)
        {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
