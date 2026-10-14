class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        for (auto ch : s) {
            freq[ch]++;
        }
        sort(s.begin(), s.end(), [&freq](auto lhs, auto rhs) {
            // lhs and rhs are chars
            return freq[lhs] > freq[rhs] || (freq[lhs] == freq[rhs] && lhs > rhs);
            });

        return s;
    }
};