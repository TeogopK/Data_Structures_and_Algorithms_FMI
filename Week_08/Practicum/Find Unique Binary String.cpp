// a solution using diagonalization
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        std::string diagonal(nums.size(), '0');
        for (int i = 0; i < nums.size(); ++i) {
            diagonal[i] = (nums[i][i] == '0') ? '1' : '0';
        }

        return diagonal;
    }
};

// a solution with generating all strings with length n over the alphabet {0, 1}
class Solution {
public:
    set<string> s;
    string ans, curr;

    void backtracking(int n) {
        if(!ans.empty())
            return;
        
        if(n == 0) {
            if (s.count(curr) == 0)
                ans = curr;
            return;
        }

        curr += '0';
        backtracking(n - 1);
        curr.pop_back();

        curr += '1';
        backtracking(n - 1);
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        for (auto str : nums) {
            s.insert(str);
        }
        backtracking(nums.size());
        return ans;
    }
};

//solution using sorting to find the first string not inside of nums
class SortSolution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        std::sort(nums.begin(), nums.end());
        int len = nums[0].size();
        int i = 0;
        while(i < nums.size())
        {
            if (!isStringRepres(nums[i], i))
            {
                std::cout<<i<<std::endl;
                return stringRepres(i, len);
            }
            i++;
        }
        return stringRepres(i,);
    }
private:
    bool isStringRepres(const std::string& str, int num)
    {
        for(int i = str.size() - 1; i >= 0; i--)
        {
            if (num % 2 != str[i] - '0')
            {
                return false;
            }
            num /= 2;
        }
        return true;
    }

    std::string stringRepres(int n, int k)
    {
        std::string s;
        while (n > 0)
        {
            s = (char)('0' + (n % 2)) + s;
            std::cout<<s<<std::endl;
            n/=2;
            k--;
        }
        while(k > 0)
        {
            s = '0' + s;
            k--;
        }
        return s;
    }
};
