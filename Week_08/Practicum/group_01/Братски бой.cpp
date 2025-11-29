#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> have(N), want(N);
    for (int i = 0; i < N; i++)
        cin >> have[i];
    for (int i = 0; i < N; i++)
        cin >> want[i];

    unordered_map<int, int> count;
    int badDays = 0;

    for (int i = 0; i < N; i++)
    {
        int sticker = have[i];
        int ask = want[i];

        // Иванчо получава стикера за деня
        count[sticker]++;

        // брат му иска определен стикер
        if (count[ask] > 0)
        {
            count[ask]--; // взима стикера
        }
        else
        {
            badDays++; // Иванчо яде бой
        }
    }

    cout << badDays;
}
