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
    ListNode* reorderListUtil(ListNode*& start, ListNode* last) {
        if (!last) return nullptr;

        ListNode* tail = reorderListUtil(start, last -> next);
        if (!start || start == last || start -> next == last) {
            if (start && (start == last || start -> next == last)) {
                last -> next = nullptr;
                start = nullptr;
            } 
            return last;
        }
        
        
        ListNode* startNext = start -> next;
        start -> next = last;
        last -> next = startNext;
        start = startNext;
        return last;

       

    }
    void reorderList(ListNode* head) {
        if (!head || !head-> next) return;
        reorderListUtil(head, head);
    }
};
