#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000000];
int main() {
    size_t count;
    cin >> count;
    for(size_t i = 0; i < count; i++) {
        cin >> arr[i];
    }
    
    stack<int> s;
    size_t maxSize = 0;
    size_t maxStartingIndex = 0;
    for(int i = count - 1; i >= 0; i--) {
        int current = arr[i];
        while(!s.empty() && current >= s.top()) {
            s.pop();
        }
        s.push(current);
        if(s.size() >= maxSize) {
            maxSize = s.size();
            maxStartingIndex = i;
        }
    }
    
    cout << maxStartingIndex;
}
