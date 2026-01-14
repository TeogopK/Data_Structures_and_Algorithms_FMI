#include <bits/stdc++.h>
using namespace std;

int findIndex(char ch)
{
    if (isdigit(ch))
    {
        return ch - '0' + 26 + 26; //find start of digits
    }

    else if (isalpha(ch))
    {
        if (islower(ch))
        {
            return ch - 'a' + 26; //find start of lower letters
        }

        return ch - 'A'; //find start of upper letters
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> data(26 + 26 + 10);

    string str;
    cin >> str;
    for (size_t i = 0; i < str.size(); i++)
    {
        int at = findIndex(str[i]);
        data[at].first = i;
        data[at].second++;
    }

    sort(data.begin(), data.end());

    for (auto& p : data)
    {
        if (p.second == 1)
        {
            cout << p.first << " ";
        }
    }



    return 0;
}