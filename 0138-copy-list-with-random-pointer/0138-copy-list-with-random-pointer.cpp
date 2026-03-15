/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dup = head;
        unordered_map<Node* , Node*> mp;
        unordered_map<Node* ,int> node_idx_original;
        unordered_map<int , Node*> node_idx_new;
        Node* temp = new Node(0);
        Node* curr = temp;

        int cnt = 0;
        while (dup){
            Node* temp1 = new Node(dup->val);
            curr->next = temp1;
            curr = temp1;
            node_idx_new[cnt] = temp1;
            node_idx_original[dup] = cnt;
            mp[dup] = dup->random;
            cnt += 1;
            dup = dup->next;
        }

        dup = head;
        curr = temp->next;

        while (dup && curr){
            Node* rand = mp[dup];
            if (rand != nullptr){
                int idx = node_idx_original[rand];
                curr->random = node_idx_new[idx];
            }
            dup = dup->next;
            curr = curr->next;
        }
        return temp->next;
    }
};