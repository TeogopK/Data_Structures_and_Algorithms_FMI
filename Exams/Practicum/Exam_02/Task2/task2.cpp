#include <bits/stdc++.h>
using namespace std;

int n, k, s;

void dfs(const vector<vector<int>>& graph, int currentNode, vector<int>& components, int component) {
	components[currentNode] = component;
	for (const auto& neighbour : graph[currentNode]) {
		if (!components[neighbour]) {
			dfs(graph, neighbour, components, component);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> s;
	vector<int>components(n + 1, 0);
	vector<vector<int>>graph(n + 1, vector<int>());

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int componentIndex = 1;
	for (int i = 0; i < n; i++) {
		if (!components[i]) {
			dfs(graph, i, components, componentIndex);
		}
		componentIndex++;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << (components[s] == components[x] ? "YES\n" : "NO\n");
	}

	return 0;
}


// variant 2
#include <bits/stdc++.h>
using namespace std;

int n, k, s;
const int MAXN = 1000001;
int comp[MAXN];
int h[MAXN];

int find(int v) {
	while (comp[v] != v) {
		v = comp[v];
	}
	return comp[v];
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (h[u] > h[v]) swap(u, v);
	comp[u] = v;
	if (h[u] == h[v]) h[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		comp[i] = i;
		h[i] = 0;
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		if (find(s) == find(x)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}