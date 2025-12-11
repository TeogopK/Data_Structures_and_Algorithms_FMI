class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Building frequency map
        int freq[26] = { 0 };
        for (char& ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            // Restore updated frequencies to the heap
            for (int& x : store) {
                pq.push(x);
            }
            // Add time for the completed cycle
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};