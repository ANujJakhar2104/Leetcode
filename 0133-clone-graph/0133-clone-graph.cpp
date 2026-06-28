class Solution {
public:
    unordered_map<Node*,int> mp;
    unordered_map<Node*, Node*> N2N;

    Node* solve(Node* new_node, Node* root){
        new_node->val = root->val;
        mp[root] = 1;
        N2N[root] = new_node;

        vector<Node*> neigh;
        for(Node* temp : root->neighbors){
            if (mp.find(temp) != mp.end()) {
                neigh.push_back(N2N[temp]);
                continue;
            }
            Node* next = new Node(temp->val);
            neigh.push_back(next);
            solve(next, temp);
        }
        new_node->neighbors = neigh;
        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* root = new Node(node->val);
        return solve(root, node);
    }
};