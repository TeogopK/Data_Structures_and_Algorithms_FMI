class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        for(int i = 0; i <= k; i++) {
            // to make sure that every column is update only with data from last round + new edge
            vector<int> nextRow(distances);
            for(auto& edge: flights) {
                if(distances[edge[0]] != INT_MAX) {
                    nextRow[edge[1]] = min(nextRow[edge[1]], distances[edge[0]] + edge[2]);
                }
            }
            
            distances = std::move(nextRow);
        }
        
        if(distances[dst] == INT_MAX) {
            return -1;
        }
        
        return distances[dst];
    }
};
