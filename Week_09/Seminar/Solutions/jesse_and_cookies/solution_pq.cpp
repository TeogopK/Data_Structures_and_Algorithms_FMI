#include <iostream>
#include <queue>

int main()
{
    int n, k;
    long long num;

    long long count = 0;
    // to create a min heap
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        pq.push(num);
    }

    long long firstCookie, secondCookie, newCookie;

    while (pq.size() >= 2 && pq.top() < k)
    {
        firstCookie = pq.top();
        pq.pop();
        secondCookie = pq.top();
        pq.pop();

        newCookie = firstCookie + secondCookie * 2;
        pq.push(newCookie);
        count++;
    }

    if (pq.top() < k)
    {
        std::cout << -1;
        return 0;
    }

    std::cout << count;

    return 0;
}
