class Solution {
public:
    bool isOpening(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }
    bool isReversed(char l, char r) {
        return (l == '(' && r == ')')
            || (l == '{' && r == '}')
            || (l == '[' && r == ']');
    }
    bool isValid(string s) {
        stack<char> container;
        for(auto ch: s) {
            if(isOpening(ch)) {
                container.push(ch);
            }
            else {
                if(container.empty() || !isReversed(container.top(), ch)) {
                    return false;
                }
                
                container.pop();
            }
        }
        
        return container.size() == 0;
    }
};
