struct Order {
    int enqueueTime;
    int processingTime;
    size_t index;
};

struct EnqueueTimeComparator {
    bool operator()(const Order& lhs, const Order& rhs) const {
        return lhs.enqueueTime > rhs.enqueueTime;
    }
};

struct ProcessingTimeComparator {
    bool operator()(const Order& lhs, const Order& rhs) const {
        if(lhs.processingTime == rhs.processingTime) {
            return lhs.index > rhs.index;
        }
        return lhs.processingTime > rhs.processingTime;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<Order, vector<Order>, EnqueueTimeComparator> canNotBeStarted;
        priority_queue<Order, vector<Order>, ProcessingTimeComparator> canBeStarted;
        
        for(size_t i = 0; i < tasks.size(); i++) {
            canNotBeStarted.push({ tasks[i][0], tasks[i][1], i});
        }
        
        vector<int> result;
        size_t time = 1;
        while(!canNotBeStarted.empty() || !canBeStarted.empty()) {
            while(!canNotBeStarted.empty() && canNotBeStarted.top().enqueueTime <= time) {
                canBeStarted.push(canNotBeStarted.top());
                canNotBeStarted.pop();
            }
            
            if(canBeStarted.empty()) {
                time = canNotBeStarted.top().enqueueTime;
                continue;
            }
            
            time += canBeStarted.top().processingTime;
            result.push_back(canBeStarted.top().index);
            canBeStarted.pop();
        }
        
        return result;
    }
};
