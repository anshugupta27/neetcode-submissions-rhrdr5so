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
    ListNode* reverseListUtil (ListNode* head, ListNode*& parentHead) {
        if (!head -> next) {
            parentHead = head;
            return head ;
        }
        ListNode* nextHead = reverseListUtil (head -> next, parentHead);
        nextHead -> next = head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* parentHead = head;
        if (!head) return head;
        ListNode* lastNode = reverseListUtil(head, parentHead);
        lastNode -> next = nullptr;
        return parentHead;
        
    }
};
