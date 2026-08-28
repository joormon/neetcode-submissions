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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root) return {};
        vector<int> rightElementList;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            while(size>1)
            {
               TreeNode* curr=q.front();
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
               q.pop();
               size--;
            }

            TreeNode* rightNode=q.front();
            rightElementList.push_back(rightNode->val);
            if(rightNode->left) q.push(rightNode->left);
            if(rightNode->right)q.push(rightNode->right);
            q.pop();
        }
        
        return rightElementList;
    }
};
