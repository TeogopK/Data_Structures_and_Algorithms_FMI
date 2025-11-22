#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Решение 4: Линейно търсене
// Просто добавяме всички елементи в масив и търсим линейно

int main() {
    int n;
    cin >> n;

    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        nums.push_back(x);
    }

    long long target;
    cin >> target;

    // Търсим най-малкото число строго по-голямо от target
    long long result = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (nums[i] > target) {
            result = min(result, nums[i]);
        }
    }

    if (result == LLONG_MAX) {
        cout << "NO" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}

// Сложност:
// Време: O(N) за въвеждане + O(N) за линейно търсене = O(N)
// Памет: O(N) за вектора
// Забележка: Това е най-простото решение, но не най-ефективното при повторни заявки
