//O(2^(n + m))
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0) {
            if (p.size() == 0) {
                return true;
            } else {
                if (p.size() >= 2) {
                    if (p[1] == '*') {
                        return isMatch("", p.substr(2, p.size() - 2));
                    }
                }
                return false;
            }
        } else if (p.size() == 0) {
            return false;
        }
        if (p.size() >= 2 && p[1] == '*') {
            if ((p[0] == '.') || (s[0] == p[0])) {
                return isMatch(s.substr(1, s.size() - 1), p) || isMatch(s, p.substr(2, p.size() - 2));
            } else {
                return isMatch(s, p.substr(2, p.size() - 2));
            }
        } else if (p[0] == '.' || s[0] == p[0]) {
            return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        } else {
            return false;
        }
    }
};
