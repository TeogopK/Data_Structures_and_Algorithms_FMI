class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        dict.erase(beginWord);
    
        queue<pair<string, int>> weigths;
        weigths.push({beginWord, 1});


        while(!weigths.empty()) {

            string curStr = weigths.front().first;
            int curWeigth = weigths.front().second;
            weigths.pop();
            
            for(int i = 0; i < curStr.size(); ++i) {
                char charToRevert = curStr[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    curStr[i] = c;
                    if (dict.count(curStr) == 1) {
                        if (curStr == endWord) {
                            return curWeigth + 1;
                        }
                        weigths.push({curStr, curWeigth + 1});
                        dict.erase(curStr);
                    }
                    curStr[i] = c;
                } 
                curStr[i] = charToRevert;
            }
        }

        return 0;
    }
};
