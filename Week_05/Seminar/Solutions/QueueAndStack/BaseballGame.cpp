class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> values;
        for(auto& op: operations) {
            if(op == "+") {
                int currTop = values.top();
                values.pop();
                int newValue = values.top() + currTop;
                values.push(currTop);
                values.push(newValue);
            }
            else if(op == "D") {
                values.push(2 * values.top());
            }
            else if(op == "C") {
                values.pop();
            }
            else {
                values.push(stoi(op));
            }
        }
        int sum = 0;
        while(!values.empty()) {
            sum += values.top();
            values.pop();
        }
        return sum;
    }
};