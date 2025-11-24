#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin>>prices[i];
    }
    
    stack<int>s;
    
    vector<int>nextGreater(N, -1);
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        if (!s.empty()) {
		nextGreater[i] = s.top();
	}
        s.push(i);
    }
    
    for (int i = 0; i < N; i++) {
        nextGreater[i] == -1 ? cout << 0 <<" " : cout << nextGreater[i] - i << " ";
    }
    
    return 0;
}
