// https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> values, minStack;

public:
    MinStack() {}

    void push(int x) {
        values.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (values.top() == minStack.top())
            minStack.pop();
        values.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minStack.top();
    }
};
