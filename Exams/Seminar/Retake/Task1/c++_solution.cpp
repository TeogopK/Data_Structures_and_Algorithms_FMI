#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if (freq[a] == freq[b]) {
            return a > b;
        }
        return freq[a] < freq[b];
    });

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}
