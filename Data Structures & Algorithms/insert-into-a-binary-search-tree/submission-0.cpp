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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==nullptr)
        {
            root=new TreeNode(val);
            return root;
        }
        
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            //for duplicate values
            if(curr->val== val)
                return root;
            
            if(curr->val < val)
            {
                if(curr->right)
                {
                    curr=curr->right;
                }
                else
                {
                    curr->right=new TreeNode(val);
                    return root;
                }
            }
            else
            {
                if(curr->left)
                {
                    curr=curr->left;
                }
                else
                {
                    curr->left=new TreeNode(val);
                    return root;
                }
            }
        }
    }
};