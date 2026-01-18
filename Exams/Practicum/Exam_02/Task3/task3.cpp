#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 500001;
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		comp[i] = i;
		h[i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	long long q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			cout << (find(a) == find(b));
		}
		else {
			merge(a, b);
		}
	}

	return 0;
}
