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
    void removeNthFromEndUtil(ListNode* prev, ListNode* curr, int n , int &nodeCount, bool &flag) {
        if (!curr) return;
        removeNthFromEndUtil(prev -> next, curr -> next, n , nodeCount, flag);
        nodeCount++;
        if (nodeCount == n) {
            prev -> next = curr -> next;
            flag = true;
        }

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || ! head -> next) {
            if (n == 1) return nullptr;
        }
        int count = 0;
        bool flag = false;
        removeNthFromEndUtil(head, head -> next, n , count, flag);
        count++;
        if (!flag && count == n) return head -> next;
        return head;
    }
};
