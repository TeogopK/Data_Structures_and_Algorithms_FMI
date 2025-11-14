class SmallestInfiniteSet {
    set<int> smallest;
    int numbersUpTo = 1;
public:
    int popSmallest() {
        if (smallest.empty()) {
            return numbersUpTo++;
        }

        int result = *smallest.begin();
        smallest.erase(smallest.begin());
        return result;
    }

    void addBack(int num) {
        if (num >= numbersUpTo) {
            return;
        }
        smallest.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */