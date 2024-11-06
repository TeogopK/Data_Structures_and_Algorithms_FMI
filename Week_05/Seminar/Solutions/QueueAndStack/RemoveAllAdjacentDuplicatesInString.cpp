class Solution {
public:
    string removeDuplicates(string s) {
        // used as stack
        string result;
        
        for(auto ch: s) {
            if(result.size() == 0) {
                result.push_back(ch);
                continue;
            }
            
            if(result.back() == ch) {
                result.pop_back();
            }
            else {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};
