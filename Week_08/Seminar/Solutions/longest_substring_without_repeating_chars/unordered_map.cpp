class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // key - character
        // value - last seen index
        unordered_map<char, size_t> c;
        
        int maxSize = 0;
        int currentStart = 0;
        for(size_t i = 0; i < s.size(); i++) {
            auto iter = c.find(s[i]);
            // you should check if the last seen index is before the start!
            if(iter != c.end() && iter->second >= currentStart) {
                currentStart = iter->second + 1;
            }
            
            c[s[i]] = i;
            if(i - currentStart + 1 > maxSize) {
                maxSize = i - currentStart + 1;
            }
        }
        return maxSize;
    }
};
