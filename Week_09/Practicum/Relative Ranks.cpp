class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        vector<string> answears(score.size());

        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        int i = 0;
        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            i++;

            pq.pop();
            if (i == 1) {
                answears[curr.second] = "Gold Medal";
            } else if (i == 2) {
                answears[curr.second] = "Silver Medal";
            } else if (i == 3) {
                answears[curr.second] = "Bronze Medal";
            } else {
                answears[curr.second] = to_string(i);
            }
        }

        return answears;
    }
};

// alternative
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < score.size(); ++i) {
            pq.push({ score[i], i });
        }

        std::vector<std::string> ranks(score.size(), "");
        if (score.size() >= 1) {
            ranks[pq.top().second] = "Gold Medal";
            pq.pop();
        }

        if (score.size() >= 2) {
            ranks[pq.top().second] = "Silver Medal";
            pq.pop();
        }

        if (score.size() >= 3) {
            ranks[pq.top().second] = "Bronze Medal";
            pq.pop();
        }

        for (int i = 3; i < score.size(); ++i) {
            ranks[pq.top().second] = to_string(i + 1); 
            pq.pop();  
        }

        return ranks;
    }
};
