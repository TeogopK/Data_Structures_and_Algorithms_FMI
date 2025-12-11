class MedianFinder {
    vector<int> store;

public:
    void addNum(int num) {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    double findMedian() {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double)store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};