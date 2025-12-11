struct Comparator {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
        return lhs[0] * lhs[0] + lhs[1] * lhs[1] > rhs[0] * rhs[0] + rhs[1] * rhs[1];
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq(points.begin(), points.end());
        
        vector<vector<int>> result;
        for(int _ = 0; _ < k; _++) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};
