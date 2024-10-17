#include <algorithm>
#include <string>

class Solution
{
public:
    char findTheDifference(std::string s, std::string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        int N = s.size();

        for (int i = 0; i < N; i++)
        {
            if (s[i] != t[i])
            {
                return t[i];
            }
        }
        return t[N];
    }
};