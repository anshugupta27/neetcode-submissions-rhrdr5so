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
    void goodNodesUtil (TreeNode* root, int maxVal, int &countGoodNodes) {
        if (!root) return;
        if (root -> val >= maxVal) countGoodNodes++;
       
        goodNodesUtil (root -> left, max(maxVal, root -> val), countGoodNodes);
        goodNodesUtil (root -> right, max(maxVal, root -> val), countGoodNodes);
    }
    int goodNodes(TreeNode* root) {
        int maxVal = INT_MIN, countGoodNodes = 0;
        goodNodesUtil (root, maxVal, countGoodNodes);
        return countGoodNodes;
    }
};
