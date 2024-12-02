class Solution {
public:
    int n, mod = 1e9 + 7, base = 31;
    long long h[2001], pow[2001];
    unordered_set<long long> seen;

    long long get_rolling_hash(int left, int right)
    {
        // We are adding the mod in the end, because if the subtraction results in a number
        // < 0, then we get negative result, which we should avoid when working with mods.
        return ((h[right] - h[left - 1] * pow[right - left + 1]) % mod + mod) % mod;
    }

    int distinctEchoSubstrings(string text)
    {
        n = text.size();
        text = ' ' + text; // Adding this for ease when calculating hashes

        pow[0] = 1, h[0] = 0;
        for(int i = 1; i <= n; i++) pow[i] = (long long)base * pow[i - 1] % mod;
        for(int i = 1; i <= n; i++) h[i] = (h[i - 1] * 31 + text[i] - 'a' + 1) % mod;

        int k = 2;

        while(k <= n)
        {
            for(int i = 1; i + k - 1 <= n; i++)
            {
                if ( seen.find(get_rolling_hash(i, i + k - 1)) == seen.end() &&
                get_rolling_hash(i, i + k / 2 - 1) == get_rolling_hash(i + k / 2, i + k - 1) )
                {
                    seen.insert(get_rolling_hash(i, i + k - 1));
                }
            }
            k += 2;
        }
        return seen.size();
    }
};
