class Solution {
    // pointer value is a number => can be hashed
    unordered_map<Node*, Node*> indexToNode;
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        
        auto iter = indexToNode.find(node);
        if(iter != indexToNode.end()) {
            return iter->second;
        }
        
        Node* newNode = new Node(node->val);
        indexToNode[node] = newNode;
        
        for(auto neighbour: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbour));
        }
        
        return newNode;
    }
};
