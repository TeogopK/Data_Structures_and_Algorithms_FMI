#include <bits/stdc++.h>
using namespace std;


int main() {

    map<string, int> mp;
    string word;

    while (cin >> word)
    {
        mp[word]++;
    }

    for (auto& p : mp)
    {
        if (p.second == 1)
        {
            cout << p.first << endl;
        }
    }

    return 0;
}
