class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> words;
        unordered_map<string, char> chars;

        stringstream ss(s);
        string cur;
        
        for(char c : pattern) {
            
            if(!(ss >> cur)) return false;

            cout << cur;
            if ((words[c] == "") && (chars[cur] == '\0')) {
                chars[cur] = c;
                words[c] = std::move(cur);
            } else if (words[c] != cur || chars[cur] != c) {
                return false;
            }
        }
        if (ss >> cur) return false;
        return true;
    }
};
