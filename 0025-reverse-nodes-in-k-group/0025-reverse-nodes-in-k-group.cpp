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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* temp = head;
        ListNode* ans = new ListNode(0);;
        ListNode* temp1 = ans;

        while (temp){
            int cnt =0;
            ListNode* gp = nullptr;
            ListNode* last = nullptr;

            while (cnt != k && temp){
                cnt += 1;
                ListNode* node = new ListNode(temp->val);
                node->next = gp;
                gp = node;
                if (cnt == 1){
                    last = node;
                }
                temp = temp->next;
            }
            if (cnt == k){
                temp1->next = gp;
                temp1 = last;
            }
            else{
                ListNode* curr = gp;
                ListNode* prev = nullptr;

                while (curr) {
                    ListNode* nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }

                temp1->next = prev;
            }
        }
        return ans->next;
    }
};