class Solution {
public:
    string transformString(string s) {
        unordered_map<char, int> indexMapping;
        string str;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (indexMapping.find(c) == indexMapping.end()) {
                indexMapping[c] = i;
            }

            str.append(to_string(indexMapping[c]));
            str.append(" ");
        }
        return str;
    }

    bool isIsomorphic(string s, string t) {
        return transformString(s) == transformString(t);
    }
};