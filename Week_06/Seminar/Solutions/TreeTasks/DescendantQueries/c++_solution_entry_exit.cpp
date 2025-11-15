#include <vector>
#include <string>
using namespace std;

struct Node {
    int value;
    vector<Node*> children;
};

void dfs(Node* node, vector<int>& entry, vector<int>& exit, int& timer) {
    entry[node->value] = ++timer;
    for (Node* child : node->children)
        dfs(child, entry, exit, timer);
    exit[node->value] = ++timer;
}

// values will be unique in the range 1 to N
vector<bool> answerQueries(Node* root, const vector<pair<int, int>>& queries, int N) {
    vector<int> entry(N + 1), exit(N + 1);
    int timer = 0;
    dfs(root, entry, exit, timer);

    vector<bool> results;
    for (const auto& q : queries) {
        int descendant = q.first;
        int ancestor = q.second;
        bool isDesc =
           entry[ancestor] <= entry[descendant] &&
           exit[ancestor] >= exit[descendant];
        results.push_back(isDesc);
    }
    return results;
}
