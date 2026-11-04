// https://leetcode.com/problems/backspace-string-compare/

class Solution {
    stack<char> build(const string& str) {
        stack<char> result;

        for(auto ch: str) {
            if(ch == '#') {
                if(!result.empty()) {
                    result.pop();
                }
            }
            else {
                result.push(ch);
            }
        }

        return result;
    }

public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1 = build(s), s2 = build(t);

        if(s1.size() != s2.size()) {
            return false;
        }
        
        while(!s1.empty()) {
            if(s1.top() != s2.top()) {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        
        return true;
    }
};
