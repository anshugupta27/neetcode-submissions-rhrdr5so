/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inorderTraversal (TreeNode* root, int &k, int &finalAns) {
        if (!root) return;
        
        
        inorderTraversal (root -> left, k, finalAns);
        k--;
        if (k == 0) {
            finalAns = root -> val;
            return;
        }
        inorderTraversal (root -> right, k ,finalAns);


    }
    int kthSmallest(TreeNode* root, int k) {
        int finalAns = -1;
        inorderTraversal (root, k, finalAns);
        return finalAns;
    }
};
