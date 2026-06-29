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
    int n;
    ListNode* solve(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n += 1;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = slow->next;
        slow->next = nullptr;

        ListNode* rev = solve(secondHead); 
        ListNode* temp = head;

        while (rev){
            ListNode* fir = temp->next;
            ListNode* sec = rev->next;

            temp->next = rev;
            rev->next = fir;

            temp = fir;
            rev = sec;
        }
    }
};