#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int m;
    cin >> m;
    vector<int> y(m);
    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int sum = 0;
    size_t atX = 0;
    size_t atY = 0;

    while (atX < x.size() && atY < y.size())
    {
        if (x[atX] == y[atY])
        {
            sum += x[atX];
            while (atX < x.size() - 1 && x[atX + 1] == x[atX])
            {
                atX++;
            }

            while (atY < y.size() - 1 && y[atY + 1] == y[atY])
            {
                atY++;
            }

            atX++;
            atY++;
        }

        else if (x[atX] > y[atY])
        {
            atY++;
        }

        else
        {
            atX++;
        }

    }

    cout << sum;

    return 0;
}
