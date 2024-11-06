class Solution {
public:
    bool isOperator(const string& ch) {
        return ch == "+" || ch == "-" || ch == "*" || ch == "/";
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> expression;
        
        for(size_t i = 0; i < tokens.size(); i++) {
            if(isOperator(tokens[i])) {
                int v2 = expression.top();
                expression.pop();
                int v1 = expression.top();
                expression.pop();
                if(tokens[i] == "+") {
                    expression.push(v1 + v2);
                }
                else if(tokens[i] == "*") {
                    expression.push(v1 * v2);
                }
                else if(tokens[i] == "-") {
                    expression.push(v1 - v2);
                }
                else if(tokens[i] == "/") {
                    expression.push(v1 / v2);
                }
            }
            else {
                expression.push(stoi(tokens[i]));
            }
        }
        
        return expression.top();
    }
};