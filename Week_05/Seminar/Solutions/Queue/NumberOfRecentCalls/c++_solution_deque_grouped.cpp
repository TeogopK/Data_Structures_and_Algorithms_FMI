// https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
public:
    // grouping multiple calls at the same time will lead to less q.pop()
    deque<pair<int, int>> container; // {time, calls at that time}
    int total = 0;

    int ping(int t) {
        while(!container.empty() && container.front().first < t - 3000) {
            total -= container.front().second;
            container.pop_front();
        }

        if(!container.empty() && container.back().first == t) {
            container.back().second++;
        } else {
            container.push_back({t, 1});
        }
        total++;

        return total;
    }
};
