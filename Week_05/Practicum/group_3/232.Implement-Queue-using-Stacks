class MyQueue {
    std::stack<int> lifoStack;
    std::stack<int> fifoStack;
public:
    MyQueue() {
        this->lifoStack = stack<int>();
        this->fifoStack = stack<int>();
    }
    
    void push(int x) {
        lifoStack.push(x);
    }
    
    int pop() {
        if (fifoStack.empty()) {
            while(!lifoStack.empty()) {
                fifoStack.push(lifoStack.top());
                lifoStack.pop();
            }
        }
        int popped = fifoStack.top();
        fifoStack.pop();
        return popped;
    }
    
    int peek() {
        if (fifoStack.empty()) {
            while(!lifoStack.empty()) {
                fifoStack.push(lifoStack.top());
                lifoStack.pop();
            }
        }
        return fifoStack.top();
    }
    
    bool empty() {
        return lifoStack.empty() && fifoStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
