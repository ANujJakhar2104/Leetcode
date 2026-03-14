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
    int solve(ListNode* head){
        int n = 0;
        while (head){
            n += 1;
            head = head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = solve(head);
        int req = sz - n;
        if (req == 0) return head->next;
        int curr = 0;
        ListNode* temp = head;
        while (curr != req-1){
            curr += 1;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;

    }
};