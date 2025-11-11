class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s_st = build(s);
        stack<char> t_st = build(t);

        if (s_st.size() != t_st.size())
        {
            return false;
        }

        while (!s_st.empty())
        {
            if (s_st.top() != t_st.top())
            {
                return false;
            }
            s_st.pop();
            t_st.pop();
        }

        return true;
    }

private:
    stack<char> build(const string &str)
    {
        stack<char> st;
        for (char c : str)
        {
            if (c != '#')
            {
                st.push(c);
            }
            else if (!st.empty())
            {
                st.pop();
            }
        }
        return st;
    }
};
