#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i)
        {
            digits[i] += 1;
            digits[i] %= 10;

            if (digits[i] != 0)
            {
                return digits;
            }
        }

        // If all digits are zero, insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
