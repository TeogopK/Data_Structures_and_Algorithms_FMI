class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;

        for (char task : tasks) {
            taskCount[task]++;
        }

        priority_queue<int> pq;
        for (auto& el : taskCount) {
            pq.push(el.second);
        }

        int time = 0;
        queue<pair<int, int>> waitQueue;

        while (!pq.empty() || !waitQueue.empty()) {
            time++;
            if (!waitQueue.empty() && waitQueue.front().second == time) {
                pq.push(waitQueue.front().first);
                waitQueue.pop();
            }
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                if (freq > 1) {
                    waitQueue.push({freq - 1, time + n + 1});
                }
            }
        }

        return time;
    }
};