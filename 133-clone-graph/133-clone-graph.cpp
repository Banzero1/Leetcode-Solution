class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
    
    Node* dfs(Node* node) {
        if (map.find(node) != map.end()) return map[node];
        Node* clone = new Node(node->val);
        map[node] = clone; // map OLD node to NEW node!
        for (Node* nei : node->neighbors)
            clone->neighbors.push_back(dfs(nei));
        return clone;
    }
};