class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int iter = digits.size() - 1;
        int takeOver = 1;
        while (iter >= 0 && takeOver > 0)
        {
            digits[iter]++;
            digits[iter] %= 10;
            takeOver = (digits[iter] == 0);
            iter--;
        }

        if (iter == -1 && takeOver)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};