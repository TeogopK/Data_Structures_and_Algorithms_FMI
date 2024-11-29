class Solution {
    int base1 = 113;
    long long mod1 = 1e9 + 7;
    long long pow1[(int)1e4 + 1] {};
    
    void calcPowers(int size, long long *pow, int base, int mod) {
        pow[0] = 1;
        for (int i = 1; i < size; ++i) {
            pow[i] = (pow[i - 1] * base) % mod;
        }
    }

    long long hash(std::vector<int>& nums, int size, long long *pow, long long mod) {
        long long hash = 0;
        for (int i = 0; i < size; ++i) {
            hash += nums[i] * pow[size - 1 - i];
            hash %= mod;
        }
        return hash;
    }

    long long rollingHash(int prev, int prevHash, int next, int size, long long *pow, int 
base, long long mod) {
        long long nextHash = (prevHash - prev * pow[size - 1]) % mod;
        nextHash = nextHash < 0 ? nextHash + mod : nextHash;
        return (nextHash * base + next) % mod;
    }

    bool hasCommonSubarray(std::vector<int>& nums1, std::vector<int>& nums2, int size) {
        std::unordered_set<long long> hashes1;
        long long h1 = hash(nums1, size, pow1, mod1);
        hashes1.insert(h1);

        for (int i = 1; i <= nums1.size() - size; ++i) {
            hashes1.insert(h1 = rollingHash(nums1[i - 1], h1, nums1[i + size - 1], size, 
pow1, base1, mod1));
        }

        h1 = hash(nums2, size, pow1, mod1);

        if (hashes1.count(h1)) {
            return true;
        }

        for (int i = 1; i <= nums2.size() - size; ++i) {
            h1 = rollingHash(nums2[i - 1], h1, nums2[i + size - 1], size, pow1, base1, 
mod1);
            if (hashes1.count(h1)) {
                return true;
            }
        }

        return false;
    }  
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }
        calcPowers(nums1.size(), pow1, base1, mod1);
        
        int left = 1;
        int right = nums1.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasCommonSubarray(nums1, nums2, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};
