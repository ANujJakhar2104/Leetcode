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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* temp = &head;
        int carry = 0;
        while (l1 || l2 || carry){
            int sum = carry;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            temp->next = curr;
            temp = temp->next;
        }
        return head.next;
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         long long num1=0 ,num2=0;
//         ListNode* temp1=l1;
//         ListNode* temp2=l2;
//         while(temp1 || temp2){
//             if (temp1){
//                 num1 = num1*10 + temp1->val;
//                 temp1 = temp1->next;
//             }
//             if (temp2){
//                 num2 = num2*10 + temp2->val;
//                 temp2 = temp2->next;
//             }
//         }
//         num1 += num2;
//         string num = to_string(num1);

//         ListNode head(0);
//         ListNode* temp = &head;
//         for(char ch : num){
//             ListNode* curr =new ListNode(ch-'0');
//             temp->next = curr;
//             temp = temp->next;
//         }
//         return head.next;
//     }
// };