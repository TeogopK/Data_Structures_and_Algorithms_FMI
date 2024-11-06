class MinStack {
public:
    long long currentMin = 0;
    stack<long long> container;
    
    MinStack() {}
    
    void push(int val) {
        if(container.empty()) {
            currentMin = val;
            container.push(val);
            return;
        }
        
        
        if(val >= currentMin) {
            container.push(val);
        }
        else {
            // we have new min
            container.push(2 *1LL * val - currentMin);
            currentMin = val;
        }
    }
    
    void pop() {
        if(container.size() == 1) {
            container.pop();
            return;
        }
        
        if(container.top() >= currentMin) {
            container.pop();
        }
        else {
            currentMin = 2* 1LL * currentMin  - container.top();
            container.pop();
        }
    }
    
    int top() {
        if(container.top() >= currentMin) {
            return container.top();
        }
        else {
            return currentMin;
        }
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