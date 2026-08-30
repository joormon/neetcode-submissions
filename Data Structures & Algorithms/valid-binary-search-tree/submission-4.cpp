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
    bool helper(TreeNode* node, long long minValue, long long maxValue) {
        if (!node) return true;

        if (node->val <= minValue || node->val >= maxValue) return false;

        return helper(node->left, minValue, node->val) && helper(node->right, node->val, maxValue);
    }

   public:
    bool isValidBST(TreeNode* root) { return helper(root, LLONG_MIN, LLONG_MAX); }
};
