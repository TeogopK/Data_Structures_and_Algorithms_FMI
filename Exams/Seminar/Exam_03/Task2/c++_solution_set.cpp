#include <iostream>
#include <set>
using namespace std;

// Решение 2: Използване на set и upper_bound
// set автоматично поддържа елементите сортирани и уникални

int main() {
    int n;
    cin >> n;

    set<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.insert(x);
    }

    int target;
    cin >> target;

    // upper_bound в set връща итератор към първия елемент строго по-голям от target
    auto it = nums.upper_bound(target);

    if (it == nums.end()) {
        cout << "NO" << endl;
    }
    else {
        cout << *it << endl;
    }

    return 0;
}

// Сложност:
// Време: O(N*logN) за вмъкване на N елемента + O(logN) за upper_bound = O(N*logN)
// Памет: O(N) за set-a
// Забележка: set използва Red-Black Tree вътрешно
