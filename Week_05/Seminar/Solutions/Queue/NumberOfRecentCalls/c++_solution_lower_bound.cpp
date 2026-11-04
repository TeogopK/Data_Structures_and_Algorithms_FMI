// https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
public:
    vector<int> calls; // sorted, because t is strictly increasing

    int ping(int t) {
        calls.push_back(t);

        auto first = lower_bound(calls.begin(), calls.end(), t - 3000);
        return calls.end() - first;
    }
};
