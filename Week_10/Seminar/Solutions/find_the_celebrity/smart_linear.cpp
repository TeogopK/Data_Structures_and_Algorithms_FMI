// logical deduction - 
// - if potential celebrity knows the next one:
//   => the actual celebrity should not know anybody => the next one is the new potential
// - if potential celebrity doesn't know the next one:
//   => the next one is not the celebrity - there is atleast one pearson who doesn't know the next one
//   => the potential stays the same
// bonus iteration with the potential to verify
// - you are not sure for the people before the potential!
class Solution {
public:
    int findCelebrity(int n) {
        int potentialCelebrity = 0;
        for(int i = 1; i < n; i++) {
            if(knows(potentialCelebrity, i)) {
                potentialCelebrity = i;
            }
        }
        
        return isCelebrity(potentialCelebrity, n) ? potentialCelebrity : -1;
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
