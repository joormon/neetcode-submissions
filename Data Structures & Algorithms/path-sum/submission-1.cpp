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
    bool helper(TreeNode* root,const int& targetSum,int& sum){
        if(!root) return false;
        sum+=root->val;

        if(!root->left && !root->right){
            bool found = bool(sum==targetSum);
            sum-=root->val;
            return found;
        }

        bool found= helper(root->left,targetSum,sum) || helper(root->right,targetSum,sum);
        sum-=root->val;
        return found;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return helper(root,targetSum,sum);
    }
};