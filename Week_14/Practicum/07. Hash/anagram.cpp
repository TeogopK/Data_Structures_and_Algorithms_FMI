#include <bits/stdc++.h>
using namespace std;


int main() {

    int q;
    cin >> q;
    while (q--)
    {
        unordered_map<string, int> f, s;
        int m, n;
        cin >> m >> n;

        while (m--)
        {
            string word;
            cin >> word;
            f[word]++;
        }

        while (n--)
        {
            string word;
            cin >> word;
            s[word]++;
        }

        bool isAnagram = true;
        for (auto& p : s)
        {
            if (p.second > f[p.first])
            {
                isAnagram = false;
                break;
            }
        }

        cout << (isAnagram ? "Yes" : "No") << endl;
    }

    return 0;
}