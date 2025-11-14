class SmallestInfiniteSet {
    set<int> smallest;
public:
    SmallestInfiniteSet() {
        // populate the set with all the nums 1 to 1000
        std::vector<int> vec(1000);
        std::iota(vec.begin(), vec.end(), 1);
        smallest = std::set<int>(vec.begin(), vec.end());
    }
    int popSmallest() {
        int result = *smallest.begin();
        smallest.erase(smallest.begin());
        return result;
    }

    void addBack(int num) {
        smallest.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */