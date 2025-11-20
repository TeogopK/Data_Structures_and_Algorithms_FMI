class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10)
            return {};

        unordered_set<string> res;
        unordered_set<string> set;

        set.insert(s.substr(0, 10));

        for (int i = 1; i <= s.size() - 10; i++) {
            string cur = s.substr(i, 10);
            if (set.count(cur)) {
                res.insert(cur);
            }
            set.insert(cur);
        }

        vector<string> result;
        for (auto& el : res) {
            result.push_back(el);
        }

        return result;
    }
};