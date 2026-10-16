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
    // One stack + lastVisited
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;
        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();
                if (node->right && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    lastVisited = node;
                    result.push_back(node->val);
                    st.pop();
                }
            }
        }

        return result;
    }
};