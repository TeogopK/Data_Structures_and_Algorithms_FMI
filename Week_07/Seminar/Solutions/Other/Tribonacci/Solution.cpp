class Solution {
public:
    int _tribonacci(int n, size_t* cache) {
        if(n == 0) {
            return 0;
        }

        if(n == 1 || n == 2) {
            return 1;
        }

        if(cache[n - 1] == 0) {
            cache[n - 1] = _tribonacci(n - 1, cache);
        }

        if(cache[n - 2] == 0) {
            cache[n - 2] = _tribonacci(n - 2, cache);
        }

        if(cache[n - 3] == 0) {
            cache[n - 3] = _tribonacci(n - 3, cache);
        }

        return cache[n - 1] + cache[n - 2] + cache[n - 3];
    }

    int tribonacci(int n) {
        // try not to use these dynamic memory allocation...
        size_t* cache = new size_t[n]();
        int result = _tribonacci(n, cache);
        delete[] cache;

        return result;
    }
};