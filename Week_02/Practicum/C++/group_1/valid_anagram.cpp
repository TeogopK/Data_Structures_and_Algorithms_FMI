// https://leetcode.com/problems/valid-anagram

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Early exit if sizes differ
        if (s.size() != t.size())
        {
            return false;
        }

        // Character count for 'a' to 'z'
        vector<int> charCount(26, 0);

        for (size_t i = 0; i < s.size(); i++)
        {
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }

        // Check if all counts are zero
        for (int count : charCount)
        {
            if (count != 0)
            {
                return false;
            }
        }

        return true;
    }
};