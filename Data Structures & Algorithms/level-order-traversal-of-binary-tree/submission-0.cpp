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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> finalAns;
        while (q.size()) {
            int size = q.size();
            vector<int> tempVec;
            while (size--) {
                TreeNode* front = q.front();
                if (front -> left) q.push(front -> left);
                if (front -> right) q.push(front -> right);
                tempVec.push_back(front -> val);
                q.pop();
            }
            finalAns.push_back(tempVec);
        }
        return finalAns;
    }
    
};
