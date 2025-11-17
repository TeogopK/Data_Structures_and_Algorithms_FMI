class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            res[sorted].push_back(s);
        }

        vector<vector<string>> resVect;
        resVect.reserve(res.size());
        for(auto& s : res) {
            resVect.push_back(std::move(s.second));
        }
        return resVect;
    }
};
