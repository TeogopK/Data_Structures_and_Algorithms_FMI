//fn:
#include <bits/stdc++.h>

using namespace std;

struct Pair {
    int value;
    size_t index;
    
    bool operator<(const Pair& other) const {
        return index > other.index;
    }
};


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
    unordered_map<int, int> seen;
    priority_queue<Pair> pq;
    size_t count;
    cin >> count;
    for(size_t i = 0; i < count; i++) {
        int val;
        cin >> val;
        seen[val]++;
        if(seen[val] == 1) {
            pq.push({ val, i });
        }
        
        while(pq.size() > 0 && seen[pq.top().value] > 1) {
            pq.pop();
        }
        if(pq.empty()) {
            cout << -1 << " ";
        }
        else {
            cout << pq.top().value << " ";
        }
    }
}

 