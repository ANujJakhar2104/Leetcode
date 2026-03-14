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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list3;
        ListNode* answer = &list3;

        while(list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                answer->next = list1;
                list1 = list1->next;
            }
            else{
                answer->next = list2;
                list2 = list2->next;
            }
            answer = answer->next;
        }

        while (list1 != nullptr){
            answer->next = list1;
            list1 = list1->next;
            answer = answer->next;
        }
        while(list2 != nullptr){
            answer->next = list2;
            list2 = list2->next;
            answer = answer->next;
        }

        return list3.next;

    }
};