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
    int calculateHeight(TreeNode* root,int& maxDiameter)
    {
         if(root==NULL)
            return 0;
        int rightHeight=calculateHeight(root->right,maxDiameter);
        int leftHeight=calculateHeight(root->left,maxDiameter);

        maxDiameter=max(maxDiameter,rightHeight+leftHeight);

        return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxDiameter=0;
        calculateHeight(root,maxDiameter);
        return maxDiameter;
    }
};
