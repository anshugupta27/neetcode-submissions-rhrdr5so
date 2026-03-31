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
    int maxPathSumUtil (TreeNode *root, int &maxSum) {
        if (!root) return 0;
        int leftSubTree = maxPathSumUtil (root -> left, maxSum);
        int rightSubTree = maxPathSumUtil (root -> right, maxSum);
        maxSum = max({maxSum, leftSubTree+root->val, rightSubTree+root->val, leftSubTree + rightSubTree + root ->val, root->val});
        return max({leftSubTree+root->val, rightSubTree+root->val, root->val});


    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil (root, maxSum);
        return maxSum;

    }
};
