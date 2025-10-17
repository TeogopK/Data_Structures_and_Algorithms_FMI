bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] - a[1] < b[0] - b[1];
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] - a[1] < b[0] - b[1];
        });

        // for(auto& v: costs) {
        //     std::cout << v[0] << " " << v[1] << std::endl;
        // }

        int result = 0;
        int n = costs.size() / 2;
        for(size_t i = 0; i < n; i++) {
            result += costs[i][0] + costs[i + n][1];
        }

        return result;
    }
};
