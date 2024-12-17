#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main() {
	int towns, roads;
	std::cin >> towns >> roads;
	// key: from
	// value: key: to, value: weight
	std::unordered_map<int, std::unordered_map<int, int>> townMap;
	
	for(int i = 0; i < roads; i++) {
		int from, to, weight;
		std::cin >> from >> to >> weight;
		if(townMap.find(from) == townMap.end()) {
			townMap[from][to] = INT_MAX;
			townMap[to][from] = INT_MAX;
		}
		townMap[from][to] = std::min(townMap[from][to], weight);
		townMap[to][from] = std::min(townMap[to][from], weight);
	}

	int start, end;
	std::cin >> start >> end;
	if(townMap[start].find(end) == townMap[start].end()) {
		std::cout << -1 << std::endl;
		return 0;
	}

	std::cout << townMap[start][end] << std::endl;
}
