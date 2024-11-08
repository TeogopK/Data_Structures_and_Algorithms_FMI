class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stack;	// can be done with deque
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0 || (stack.size() && stack.top() < 0)) {
                stack.push(asteroids[i]);
                continue;
            }

            bool addNeg = true;
            while (stack.size() && stack.top() > 0 && stack.top() + asteroids[i] <= 0) {
                if (stack.top() + asteroids[i] == 0) {
                    stack.pop();
                    addNeg = false;
                    break;
                }
                stack.pop();
            }

            if (addNeg && (stack.empty() || stack.top() < 0)) {
                stack.push(asteroids[i]);
            }
        }

        int idx = stack.size();
        std::vector<int> result(idx);
        while (stack.size()) {
            result[--idx] = stack.top();
            stack.pop();
        }

        return result;
    }
};