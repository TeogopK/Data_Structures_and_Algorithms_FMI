#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(const vector<int>& rooms, int k, int minDist) {
    int count = 1;
    int lastPlacedAt = rooms[0];

    for (int i = 1; i < rooms.size(); i++) {
        if (rooms[i] - lastPlacedAt >= minDist) {
            count++;
            lastPlacedAt = rooms[i];
            if (count == k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    sort(rooms.begin(), rooms.end());

    int left = 1;
    int right = rooms[n - 1] - rooms[0];
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(rooms, k, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << result << endl;
}
