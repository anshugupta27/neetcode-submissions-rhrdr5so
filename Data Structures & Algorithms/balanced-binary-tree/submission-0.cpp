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
    int isBalancedUtil (TreeNode* root, int &isBalanced) {
        if (!root) return 0;
        int leftHeight = isBalancedUtil (root -> left, isBalanced);
        int rightHeight = isBalancedUtil (root -> right, isBalanced);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) {
            isBalanced = false;
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);

    }
    bool isBalanced(TreeNode* root) {
        int isBalanced = true;
        isBalancedUtil (root, isBalanced) ;
        return isBalanced;
    }
};
