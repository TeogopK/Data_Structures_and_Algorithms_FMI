class Solution {
public:
    // O(n) time | O(1) space
    // O(1) space because the counter length is fixed to 26
    char findTheDifference(string s, string t) {
        // vector<int> counter(26, 0);
        int counter[26]{0};
        for(auto& ch: s) {
            counter[ch - 'a']++;
        }
        for(auto& ch: t) {
            counter[ch - 'a']--;
            if(counter[ch - 'a'] == -1) {
                return ch;
            }
        }
        
        return -1;
    }
};
