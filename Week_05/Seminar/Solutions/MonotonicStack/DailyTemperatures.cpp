class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        
        // contains indexes of elements in decreasing order
        stack<int> ms;
        for(size_t i = 0; i < temperatures.size(); i++) {
            // pop all indexes of elements which are lower than the new temperature
            while(!ms.empty() && temperatures[ms.top()] < temperatures[i]) {
                // for each popped index write in the result
                result[ms.top()] = i - ms.top();
                ms.pop();
            }
            
            ms.push(i);
        }
        
        return result;
    }
};
