class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        deque<int> window;
        multiset<int> values;

        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            window.push_back(cur);

            if(window.size() > indexDiff + 1){
                values.erase(window.front());
                window.pop_front();
            }

            auto find = values.upper_bound(cur);

            if((find != values.end() && abs(cur - *find) <= valueDiff) || 
               (find != values.begin() && abs(cur - (*prev(find))) <= valueDiff)){
                return true;           
            }

           values.insert(cur);
        }

        return false;
    }
};