#include <string>

class Solution
{
public:
    char findTheDifference(std::string s, std::string t)
    {
        const int M = 'z' - 'a' + 1;
        short counts[M]{};

        for (short i = 0; i < s.size(); i++)
        {
            counts[s[i] - 'a']++;
        }

        for (short i = 0; i < t.size(); i++)
        {
            counts[t[i] - 'a']--;
        }

        for (short i = 0; i < M; i++)
        {
            if (counts[i] < 0)
            {
                return 'a' + i;
            }
        }

        return '0';
    }
};