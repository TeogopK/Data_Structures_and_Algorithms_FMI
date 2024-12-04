class MedianFinder {
public:
    // on the right side from median
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // on the left side from median
    priority_queue<int> maxHeap;
    
    void addNum(int num) {
        if(minHeap.size() == 0 || minHeap.top() < num) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        
        // move from one to the other
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
