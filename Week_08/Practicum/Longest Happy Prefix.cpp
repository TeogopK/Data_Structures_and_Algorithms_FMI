class Solution {
    int base = 31;
    long long mod = 1e9 + 7;
    long long pow[(int)1e5 + 1] {};

    void calcPowers(long long *pow, int base, long long mod, int size) {
        pow[0] = 1;
        for (int i = 1; i < size; ++i) {
            pow[i] = (pow[i - 1] * base) % mod;
        }
    }

    // hash(w.x) = hash(w).base + x % mod
    long long prefixHash(long long hash, int x, int base, long long mod) {
        return ((hash * base) % mod + x) % mod;
    }

    // hash(x.w) = x.base^|w| + hash(w) % mod
    long long suffixHash(long long hash, int length, int x, long long *pow, long long mod) {
        return (((x * pow[length]) % mod) + hash) % mod;
    }

public:
    string longestPrefix(string s) {
        if (s.size() < 2) {
            return "";
        }

        calcPowers(pow, base, mod, s.size());
        int pref = s.front() - 'a', suff = s.back() - 'a', prefIdx = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (pref == suff) {
                prefIdx = i;
            }
            pref = prefixHash(pref, s[i] - 'a', base, mod);
            suff = suffixHash(suff, i, s[s.size() - 1 - i] - 'a', pow, mod);
        }

        return s.substr(0, prefIdx);
    }
};
