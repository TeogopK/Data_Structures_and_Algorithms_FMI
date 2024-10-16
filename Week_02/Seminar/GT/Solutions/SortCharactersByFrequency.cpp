class Solution {
public:
    string frequencySort(string s) {
        int counter[256]{};
        for(auto ch: s) {
            counter[ch]++;
        }
        
        vector<pair<char, int>> container;
        for(size_t i = 0; i < 256; i++) {
            if(counter[i] != 0) {
                container.push_back(make_pair((char)i, counter[i]));
            }
        }
        sort(container.begin(), container.end(), [](auto& lhs, auto& rhs){
            return lhs.second > rhs.second;
        });
        
        string result;
        result.reserve(s.size());
        for(auto& kvp: container) {
            for(size_t i = 0; i < kvp.second; i++) {
                result += kvp.first;
            }
        }
        
        return result;
    }
};