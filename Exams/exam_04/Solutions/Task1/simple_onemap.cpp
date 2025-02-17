void intersect(vector<int>& nums1, vector<int>& nums2) {
    // for making space complexity O(min(n, m))
    // where n is the size of nums1
    // m of nums2
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }

    unordered_map<int, int> counter;
    for (auto n : nums1) {
        counter[n]++;
    }

    for (auto n : nums2) {
        auto it = counter.find(n);
        if (it != counter.end() && it->second > 0) {
            it->second--;
            cout << it->first << " ";
        }
    }
}
