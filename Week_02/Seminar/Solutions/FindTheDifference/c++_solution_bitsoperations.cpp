class Solution {
public:
    // you can reuse the idea from https://leetcode.com/problems/single-number/
    char findTheDifference(string s, string t) {
        char ch = 0;

        for (int i = 0; i < s.length(); i++) {
            ch ^= s[i];
        }
        for (int i = 0; i < t.length(); i++) {
            ch ^= t[i];
        }

        return ch;
    }
};
