#include <iostream>
#include <unordered_set>

// Works with set as well
std::unordered_set<int> s;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num, N;
    std::cin >> num >> N;

    s.insert(num);

    int numNext;
    while (N-- > 0)
    {
        std::cin >> num >> numNext;
        if (s.count(num) == 1)
        {
            s.insert(numNext);
        }
    }
    std::cout << s.size();

    return 0;
}