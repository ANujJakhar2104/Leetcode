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
        unordered_map<Node* , Node*> mp;
        unordered_map<Node* , Node*> new_to_old;

        Node *new_head = new Node(0);
        Node *temp = new_head;
        Node *old_temp = head;

        while(old_temp != nullptr){
            Node *curr = new Node(old_temp->val);
            new_to_old[curr] = old_temp;
            mp[old_temp] = curr;
            temp->next = curr;
            temp = curr;
            old_temp = old_temp->next;
        }

        temp = new_head->next;
        while(temp != nullptr){
            Node *new_random = new_to_old[temp]->random;
            temp->random = mp[new_random];
            temp = temp->next;
        }
        return new_head->next;
    }
};
