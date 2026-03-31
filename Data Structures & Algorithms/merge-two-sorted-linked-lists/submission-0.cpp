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
        ListNode* parent = new ListNode(), *ptr1 = list1, *ptr2 = list2;
        ListNode* parentPtr = parent;
        while (ptr1 && ptr2) {
            if (ptr1 -> val < ptr2 -> val) {
                parentPtr -> next = ptr1;
                ptr1 = ptr1 -> next;
                parentPtr -> next -> next = nullptr;
                parentPtr = parentPtr -> next;
            } else {
                parentPtr -> next = ptr2;
                ptr2 = ptr2 -> next;
                parentPtr -> next -> next = nullptr;
                parentPtr = parentPtr -> next;    
            }
        }
        if (ptr1) parentPtr -> next = ptr1;
        if (ptr2) parentPtr -> next = ptr2;
        return parent -> next;

        
    }
};
