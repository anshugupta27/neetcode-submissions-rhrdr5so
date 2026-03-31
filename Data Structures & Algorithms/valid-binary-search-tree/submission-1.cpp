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
    int isValidBSTUtil (TreeNode* root, int &prev) {
        if (!root) return true;
         if (prev >= root -> val) return false;
        bool leftTree = isValidBSTUtil (root -> left, prev);
        if (prev >= root -> val) return false;
        prev = root -> val;
        bool rightTree = isValidBSTUtil (root -> right, prev);
        return leftTree && rightTree;

    }
    bool isValidBST(TreeNode* root) {
        int prev = INT_MIN;
        return isValidBSTUtil (root, prev);
    }
};
