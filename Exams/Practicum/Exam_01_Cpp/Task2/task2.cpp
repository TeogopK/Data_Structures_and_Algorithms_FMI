#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

bool canSolve(int d, int n, int m, int k) {
    int groups = 0;
    int consecutive = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] <= d) {
            consecutive++;
        } else {
            groups += consecutive / k;
            if (groups >= m) {
                return true;
            }
            consecutive = 0;
        }
    }
    
    groups += consecutive / k;
    
    return groups >= m;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;
    int right = -1;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        right = max(right, arr[i]);
    }
    int answer = -1;
    
    int left = 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSolve(mid, n, m, k)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout<<answer;
    
    return 0;
}
