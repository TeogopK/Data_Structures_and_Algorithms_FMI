#include <iostream>
#include <unordered_map>
#include <queue>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::unordered_map<int, int> m;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		m[x]++;
	}

	std::priority_queue<std::pair<int, int>> pq;
	for(auto& i : m) {
		pq.push({i.second, i.first});
	}

	while(k--) {
		if(pq.empty()) {
			return 0;
		}
		auto t = pq.top();
		pq.pop();
		std::cout << t.second << std::endl;
	}
}
