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
        ListNode* l1Ptr = l1, *l2Ptr = l2, *finalHead = new ListNode(0);
        ListNode* finalPtr = finalHead;
        int carry = 0;
        while (l1Ptr || l2Ptr || carry) {
            int sum = 0;
            if (l1Ptr) {
                sum += l1Ptr -> val;
                l1Ptr = l1Ptr -> next;
            }
            if (l2Ptr) {
                sum += l2Ptr -> val;
                l2Ptr = l2Ptr -> next;
            }
            sum += carry ;
            carry = sum / 10;
            int tempSum = sum % 10;
            finalPtr -> next = new ListNode(tempSum);
            finalPtr = finalPtr -> next;
        }
        return finalHead -> next;
    }
};
