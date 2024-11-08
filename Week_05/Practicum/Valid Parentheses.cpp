#include <string>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                open.push(ch);
            } 
            else {
                if (open.empty())
                    return false;

                if ((open.top() == '(' && ch == ')') ||
                    (open.top() == '{' && ch == '}') ||
                    (open.top() == '[' && ch == ']') 
                ) {
                    open.pop();
                    continue;
                }
                return false;
            }
        }

        return open.empty();
    }

};