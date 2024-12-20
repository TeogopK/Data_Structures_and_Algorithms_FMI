class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        int currLevel = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id] = true; 

        // BFS to find friends at the target level
        while (!q.empty() && currLevel < level) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int curr = q.front();
                q.pop();
                for (auto& f : friends[curr]) {
                    if (!visited[f]) {
                        visited[f] = true;
                        q.push(f);
                    }
                }
            }
            currLevel++;
        }

        // If the desired level hasn't been reached
        if (currLevel != level) {
            return {}; // Return an empty list
        }

        // Count the frequency of each video watched by friends at the target level
        unordered_map<string, int> videoCount;
        while (!q.empty()) {
            int friendId = q.front();
            q.pop();
            for (const auto& video : watchedVideos[friendId]) {
                videoCount[video]++;
            }
        }

        // Transfer the counts to a vector of pairs for sorting
        vector<pair<int, string>> sortedVideos;
        for (const auto& p : videoCount) {
            sortedVideospush_back({p.second, p.first});
        }

        // Sort first by frequency (ascending), then by video name (lexicographical order)
        sort(sortedVideos.begin(), sortedVideos.end(), [&](const pair<int, string>& a, const pair<int, string>& b) -> bool {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> result;
        for (const auto& p : sortedVideos) {
            result.push_back(p.second);
        }

        return result;
    }
};
