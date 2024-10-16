class Solution {
public:
    char findTheDifference(string s, string t) {
        int counter[256]{0};
        for(auto& ch: s) {
            counter[ch]++;
        }
        
        for(size_t i = 0; i < t.size(); i++) {
            counter[t[i]]--;
            if(counter[t[i]] == -1) {
                return t[i];
            }
        }
        return -1;
    }
};