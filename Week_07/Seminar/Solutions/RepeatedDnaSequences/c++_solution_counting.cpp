class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counts;

        for (int i = 0; i <= s.length() - 10; i++) {
            counts[s.substr(i, 10)]++;
        }

        vector<string> result;
        for (const auto& [k, v] : counts) {
            if (v > 1) {
                result.push_back(k);
            }
        }

        return result;
    }
};
