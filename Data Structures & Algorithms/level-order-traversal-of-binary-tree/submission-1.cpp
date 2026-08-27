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
        vector<vector<int>> fl;
        q.push(root);

        while (!q.empty()) {
            vector<int> lst;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* frontEle = q.front();
                q.pop();
                lst.push_back(frontEle->val);
                if (frontEle->left) q.push(frontEle->left);
                if (frontEle->right) q.push(frontEle->right);
            }
            fl.push_back(lst);
        }

        return fl;
    }
};
