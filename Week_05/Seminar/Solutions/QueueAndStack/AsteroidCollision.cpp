class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        
        for(size_t i = 0; i < asteroids.size(); i++) {
            // if positive or its negative and last is negative
            if(asteroids[i] > 0 || result.size() > 0 && result.back() < 0) {
                result.push_back(asteroids[i]);
                continue;
            }
            
            while(result.size() > 0 && result.back() > 0 && result.back() < abs(asteroids[i])){
                result.pop_back();
            }
            
            if(result.size() == 0 || result.back() < 0) {
                result.push_back(asteroids[i]);
            }
            else if(result.back() == abs(asteroids[i])) {
                result.pop_back();
            }
        }
        return result;
    }
};