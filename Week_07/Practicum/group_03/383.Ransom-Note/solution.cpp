class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransCount;
        unordered_map<char, int> magazineCount;

        for(char c : ransomNote) {
            ransCount[c]++;
        }

        for(char c : magazine) {
            magazineCount[c]++;
        }

        for(pair<char, int> p : ransCount) {
            if (p.second > magazineCount[p.first]) {
                return false;
            }
        }
        return true;
    }
};
