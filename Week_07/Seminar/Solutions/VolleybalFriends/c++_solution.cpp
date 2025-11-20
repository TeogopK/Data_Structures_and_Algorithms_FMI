#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int m, N;
    cin >> m >> N;

    unordered_set<int> s;
    s.insert(m);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (s.find(x) != s.end()) {
            s.insert(y);
        }
    }

    cout << s.size() << endl;

    return 0;
}
