#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

struct Edge {
    int from, to, weight;
    
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DisjointSet {
    vector<int> parents;
    vector<int> size;
    
    DisjointSet(int n) : size(n + 1, 1) {
        for(int i = 0; i <= n; i++) {
            parents.push_back(i);
        }
    }
    
    int find(int v) {
        if (v == parents[v])
            return v;
        return parents[v] = find(parents[v]);
    }
    
    bool unite(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        
        if (parentU == parentV)
            return false;
        
        if (size[parentU] > size[parentV])
            swap(parentU, parentV);
        
        parents[parentU] = parentV;
        size[parentV] += size[parentU];
        
        return true;
    }
};

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> edges;
    int countEdges = g_from.size();
    
    for (int i = 0; i < countEdges; i++) {
        edges.push_back(Edge(g_from[i], g_to[i], g_weight[i]));
    }
    
    sort(edges.begin(), edges.end());
    
    int count = 0;
    int result = 0;
    DisjointSet ds(g_nodes);
    
    for (auto& edge : edges) {
        if (ds.unite(edge.from, edge.to)) {
            result += edge.weight;
            count++;
            
            if (count == g_nodes - 1)
                return result;
        }
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    fout << res;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
