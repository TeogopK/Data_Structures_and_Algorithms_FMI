class MinStack {
public:
    int currentMin = INT_MAX;
    stack<int> container;
    
    void push(int val) {
        if(val <= currentMin) {
            container.push(currentMin);
            currentMin = val;
        }
        container.push(val);
    }
    
    void pop() {
        if(container.top() == currentMin) {
            container.pop();
            currentMin = container.top();
            container.pop();
        }
        else {
            container.pop();
        }
    }
    
    int top() {
        return container.top();
    }
    
    int getMin() {
        return currentMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
