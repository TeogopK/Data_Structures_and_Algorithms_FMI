class Solution {
public:
    string removeStars(string s) {
        std::deque<char> deque;

        for (char c: s) {
            if (c == '*') {
                deque.pop_back();
            } else {
                deque.push_back(c);
            }
        }

        std::string result;
        result.reserve(deque.size());
        while (deque.size()) {
            result += deque.front();
            deque.pop_front();
        }

        return result;
    }
};