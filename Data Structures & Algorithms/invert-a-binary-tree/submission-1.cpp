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
    void swap(TreeNode*& rootLeft, TreeNode*& rootRight) {
        // if (!rootLeft || !rootRight) return;
        TreeNode* tempNode = rootLeft;
        rootLeft = rootRight;
        rootRight = tempNode;
    }
    TreeNode*  invertTreeUtil (TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root -> right);
        invertTreeUtil (root -> left);
        invertTreeUtil (root -> right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeUtil (root);
        return root;
    }
};
