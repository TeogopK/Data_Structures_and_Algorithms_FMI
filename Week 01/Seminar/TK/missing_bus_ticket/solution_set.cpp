#include <iostream>
#include <set>
#include <unordered_set>

std::unordered_set<long> s;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    long N;
    std::cin >> N;

    long num;

    for (long i = 0; i < N; i++)
    {
        std::cin >> num;
        if (num < 0)
        {
            continue;
        }

        s.insert(num);
    }

    for (long i = 1; i < 1000002; i++)
    {
        if (s.count(i) <= 0)
        {
            std::cout << i;
            break;
        }
    }

    return 0;
}