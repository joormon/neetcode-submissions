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

class Solution
{
    int calculateHeight(TreeNode* root,bool& isBalanced)
    {
        if(root==NULL)
            return 0;
        int leftHeight=calculateHeight(root->left,isBalanced);
        int rightHeight=calculateHeight(root->right,isBalanced);

        if(abs(leftHeight-rightHeight)>1)
        {
            isBalanced=false;
        }

        return 1+max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        bool isBalanced=true;
        calculateHeight(root,isBalanced);
        return isBalanced;
    }
};
