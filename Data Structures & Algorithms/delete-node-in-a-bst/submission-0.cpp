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
    TreeNode* getMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left=deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right=deleteNode(root->right, key);
        } else {
            // 2. Node found! Handle deletion safely:
            // Case 1 & 2: 0 or 1 child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;  // Unlinks node and returns child to parent
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;  // Unlinks node and returns child to parent
            }

            // Case 3: 2 children
            // Find Inorder Successor (min in right subtree)
            TreeNode* successor = getMin(root->right);

            // Copy successor value to current node
            root->val = successor->val;

            // Delete the duplicate successor node from right subtree
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};