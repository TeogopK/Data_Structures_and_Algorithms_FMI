#include <iostream>
#include <vector>

struct Edge {
	int from, to, weight;
};

int main() {
	int towns, roads;
	std::cin >> towns >> roads;
	std::vector<Edge> edges;
	
	for(int i = 0; i < roads; i++) {
		Edge edge;
		std::cin >> edge.from >> edge.to >> edge.weight;
		edges.push_back(edge);
	}

	int start, end;
	std::cin >> start >> end;

	int minWeight = INT_MAX;
	for (int i = 0; i < edges.size(); i++) {
		if(edges[i].from == start && edges[i].to == end) {
			minWeight = std::min(minWeight, edges[i].weight);
		}
	}

	if(minWeight == INT_MAX) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << minWeight << std::endl;
	}
}

