class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> s;
        for (auto str : strs) {
            auto key = str;
            std::sort(key.begin(), key.end());
            s[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& v : s) {
            result.push_back(std::move(v.second));
        }
        return result;
    }
};