class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;
        for (size_t i = 0; i < s.size(); i++) {
            auto iter = sToT.find(s[i]);
            auto iter2 = tToS.find(t[i]);
            if (iter == sToT.end() && iter2 == tToS.end()) {
                sToT[s[i]] = t[i];
                tToS[t[i]] = s[i];
                continue;
            }
            if (iter == sToT.end() || iter2 == tToS.end()) {
                return false;
            }

            if (iter->first != iter2->second) {
                return false;
            }
        }
        return true;
    }
};