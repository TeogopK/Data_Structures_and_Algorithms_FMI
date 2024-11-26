class Solution
{
public:
    string strSort(string word)
    {
        int counter[26] = {0};

        for (char c : word)
        {
            counter[c - 'a']++;
        }

        string myhash;
        for (int c = 0; c < 26; c++)
        {
            if (!counter[c])
            {
                continue;
            }

            myhash += std::to_string(counter[c]);
            myhash += (c + 'a');
        }
        std::cout << myhash << " ";

        return myhash;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto word : strs)
        {
            mp[strSort(word)].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};