#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// Lord forgive...
// start, timeNeeded, index in MinHeap
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pqToCome;

// timeNeeded, index in MinHeap
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pqWaiting;

int main()
{
    int N;
    cin >> N;

    int t, f;
    for (int i = 0; i < N; i++)
    {
        cin >> t >> f;
        auto task = make_pair(t, make_pair(f, i));
        pqToCome.push(task);
    }

    long long time = 0;

    while (!pqToCome.empty() || !pqWaiting.empty())
    {
        while (!pqToCome.empty() && pqToCome.top().first <= time)
        {                                          // .first is start
            pqWaiting.push(pqToCome.top().second); // .second is pair(final, index)
            pqToCome.pop();
        }

        if (pqWaiting.empty() && !pqToCome.empty())
        {
            time = pqToCome.top().first; // .first is start
            continue;
        }

        auto taskJustTaken = pqWaiting.top(); // pair(final, index)
        pqWaiting.pop();

        cout << taskJustTaken.second << " ";

        time += taskJustTaken.first;
    }

    return 0;
}
