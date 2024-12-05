struct Task{
    char c;
    int minTime;
    bool operator<(const Task& rhs) const {
        return minTime > rhs.minTime;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<Task> pq;
        int minTimes[26]{0};
        for(auto task: tasks) {
            pq.push({task, minTimes[task - 'A']});
            minTimes[task - 'A'] += (n + 1);
        }
        
        int currentTime = 0;
        while(!pq.empty()) {
            if(currentTime < pq.top().minTime) {
                currentTime = pq.top().minTime;
            }
            
            pq.pop();
            currentTime++;
        }
        
        return currentTime;
    }
};
