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
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;

        for(ListNode* head : lists){
            while (head){
                pq.push({head->val , head});
                head = head->next;
            }
        }

        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while (!pq.empty()){
            temp->next = pq.top().second;
            temp = temp->next;
            pq.pop();
        }
        temp->next = nullptr;
        return ans->next;
    }
};