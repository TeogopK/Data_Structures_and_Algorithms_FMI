class Solution {
public:
    int maxDepth(string s) {
        int i = 0;
        int max = 0;
        for(auto ch: s) {
            if(ch == '(') {
                i++;
                if(i > max) {
                    max = i;
                }
            }
            else if(ch == ')') {
                i--;
            }
        }
        
        return max;
    }
};