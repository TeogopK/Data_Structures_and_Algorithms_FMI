#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<double>> p(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    vector<vector<double>> dp(n, vector<double>(n, 0));
    dp[0][0] = 1.0;

    // fill first row
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - p[i][0]);
    }

    // fill first column
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] * (1 - p[0][j]);
    }

    // fill the rest of the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            double fromTop = dp[i - 1][j];
            double fromLeft = dp[i][j - 1];

            dp[i][j] = max(fromTop, fromLeft) * (1 - p[i][j]);
        }
    }

    cout << 1.0 - dp[n - 1][n - 1] << endl;
}
