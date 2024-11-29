class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> result(queries.size(), -1);
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < nums.size(); i++){
            positions[nums[i]].push_back(i);
        }

        if (positions.count(x) == 0) 
            return result;

        for (int i = 0; i < queries.size(); i++){
            if (queries[i] <= positions[x].size()) {
                result[i] = positions[x][queries[i] - 1];
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        std::vector<int> occurrences;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                occurrences.push_back(i);
            }
        }

        std::vector<int> answers(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i] <= occurrences.size()) {
                answers[i] = occurrences[queries[i] - 1];
            }
        }

        return answers;
    }
};
