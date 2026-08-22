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
    int height(TreeNode* root)
    {
        if(root==NULL)  
            return 0;
        
        return max(1+height(root->left),1+height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int currDiameter=0;
        int rightHeight=height(root->right);
        int leftHeight=height(root->left);

        currDiameter=rightHeight + leftHeight;

        int leftSubTreeDiameter=diameterOfBinaryTree(root->left);
        int rightSubTreeDiameter=diameterOfBinaryTree(root->right);

        return max({currDiameter,leftSubTreeDiameter,rightSubTreeDiameter});

        
    }
};
