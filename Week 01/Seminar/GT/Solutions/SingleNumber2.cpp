class Solution {
public:
    void addBits(unsigned n, vector<int>& counter) {
        int i = 0;
        while(n > 0) {
            if(n & 1) {
                counter[i]++;
            }
            i++;
            n /= 2;
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int> counter(32, 0);
        
        for(auto& n: nums) {
            addBits(n, counter);
        }
        
        int result = 0;
        for(size_t i = 0, powOf2 = 1; i < counter.size(); i++, powOf2*=2) {
            if(counter[i] % 3 != 0) {
                result += powOf2;
            }
        }
        
        return result;
    }
};