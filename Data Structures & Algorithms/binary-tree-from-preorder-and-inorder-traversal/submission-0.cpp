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
     unordered_map<int,int> mp;
     int preIndex=0;
    TreeNode* buildTree(vector<int>& preorder,int inStart,int inEnd)
    {
        if(inStart > inEnd) return nullptr;

        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);

        int inIndex=mp[rootVal];

        root->left=buildTree(preorder,inStart,inIndex-1);
        root->right=buildTree(preorder,inIndex+1,inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n=inorder.size();

        //map storing key:inorder_values and value: indexes;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }

        //Create the Tree;
        return buildTree(preorder,0,n-1);      
    }
};
