class Solution {
public:
    // each symbol is represent from number from 0 to 3
    int getVal(char c) {
        switch(c) {
            case 'A': return 0; break;
            case 'C': return 1; break;
            case 'G': return 2; break;
            case 'T': return 3; break;
        }
        return 0;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        const int FIXED_LENGTH = 10;
        if(s.size() <= FIXED_LENGTH) {
            return {};
        }
        
        // Only 4 possible values => we are working in 4 base (as we have 2 base numeral systems - 0101001)
        // Are there collisions in 10 base numeral system? 4 base?
        size_t rollingHash = 0;
        for(size_t i = 0; i < FIXED_LENGTH; i++) {
            rollingHash *= 4;
            rollingHash += getVal(s[i]);
        }
        // 4^9+... < size_t => no overflow
        
        // key - hash
        // value - how many times we found it
        unordered_map<size_t, size_t> hashCounter;
        hashCounter[rollingHash] = 1;
        vector<string> result;
        // 4^9 * s[0] + 4^8 * s[1] + ...... + s[9]
        // next is
        // 4^9 * s[1] + 4^8 * s[2] + ...... + s[10]
        // => newHash = (prevHash - 4^9*s[i - 10]) * 4 + s[i];
        size_t oldestSymbolMultiplier = pow(4, FIXED_LENGTH - 1);
        for(size_t i = FIXED_LENGTH; i < s.size(); i++) {
            rollingHash -= oldestNumberMultiplier * getVal(s[i - FIXED_LENGTH]);
            rollingHash *= 4;
            rollingHash += getVal(s[i]);
            
            // if we have found it once until now => this is the second time
            if(hashCounter[rollingHash] == 1) {
                result.push_back(s.substr(i - FIXED_LENGTH + 1, FIXED_LENGTH));
            }
            hashCounter[rollingHash]++;
        }
        
        return result;
    }
};
