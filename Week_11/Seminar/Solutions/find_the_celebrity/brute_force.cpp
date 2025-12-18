// check all possible

class Solution {
public:
    int findCelebrity(int n) {
        for(int i = 0; i < n; i++) {
            if(isCelebrity(i,n)) {
                return i;
            }
        }
        
        return -1;
    }
    
    bool isCelebrity(int current, int n) {
        for(int i = 0; i < n; i++) {
            if(i != current && (!knows(i, current) || knows(current, i))) {
                return false;
            }    
        }
        
        return true;        
    }
};
