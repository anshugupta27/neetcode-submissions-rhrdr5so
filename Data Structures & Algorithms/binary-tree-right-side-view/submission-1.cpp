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
    void rightSideViewUtil (TreeNode* root, int level, int &maxLevel, vector<int> &finalAns) {
        if (!root) return ;
        if (level > maxLevel) {
            maxLevel = level;
            finalAns.push_back (root -> val);
        }
        rightSideViewUtil (root -> right, level + 1, maxLevel, finalAns);
        rightSideViewUtil (root -> left, level + 1, maxLevel, finalAns);

    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 1, maxLevel = 0;
        vector<int> finalAns;
        rightSideViewUtil (root, level, maxLevel, finalAns);
        return finalAns;
 
    }
};
