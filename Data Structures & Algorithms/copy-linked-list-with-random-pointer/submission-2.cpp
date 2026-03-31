/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* currNext = curr -> next;
            Node* newNode = new Node(curr->val);
            curr -> next = newNode;
            newNode -> next = currNext;
            curr = newNode -> next;
        }
        curr = head;
        while (curr ) {
            if (curr -> random)
            curr -> next -> random = curr -> random -> next;
            else curr -> next -> random = nullptr;
            curr = curr -> next -> next;
        }
        Node* newHead = head -> next;
        Node* newCurr = newHead;
        curr = head;
        while (curr) {
            curr -> next = newCurr -> next;
            if (curr -> next)
            newCurr -> next = curr -> next -> next;
            curr = curr -> next;
            newCurr = newCurr -> next;
            
        }
        return newHead;

        
    }
};
