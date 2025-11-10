class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        int countShouldBe = 0;
        int ans = INT_MAX;
        int resLeft = 0, resRight = 0;

        vector<int> histo(128, 0);
        for(char c : t) {
            histo[c]++;
            countShouldBe++;
        }

        int left = 0, right = 0;
        int countFound = 0;

        vector<int> histoCur(128, 0);

        for (int c : s) {
            right++;
            if (histo[c] == 0) {
                continue;
            }

            histoCur[c]++;
            if (histoCur[c] > histo[c]) {
                continue;
            }
            countFound++;

            while(countFound == countShouldBe) {
                cout << left << " " << right << endl;
                if (right - left < ans) {
                    ans = right - left;
                    resLeft = left;
                    resRight = right;
                }

                if (histo[s[left]] == 0) {
                    left++;
                    continue;
                }
                histoCur[s[left]]--;
                if (histoCur[s[left]] < histo[s[left]]) {
                    countFound--;
                }
                left++;
            }
        }
        return s.substr(resLeft, resRight - resLeft);
    }
};
