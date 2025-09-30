/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int , vector<int> , greater<int>> pq;

        for(auto& it : lists){
            ListNode* temp = it;
            while (temp != nullptr){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* list = new ListNode();
        ListNode* temp = list;
        while (!pq.empty()){
            ListNode* curr = new ListNode(pq.top());
            pq.pop();
            temp->next = curr;
            temp = curr;
        }
        return list->next;
    }
};