class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        long long prevPrev = 0, prev = 1, curr;
        for (size_t i = 2; i <= n; i++) {
            curr = prevPrev + prev;
            prevPrev = prev;
            prev = curr;
        }
        return curr;
    }
};
