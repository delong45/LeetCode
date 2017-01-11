/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return sumOfChild(root->left, true) + sumOfChild(root->right, false);
    }
private:
    int sumOfChild(TreeNode* root, bool is_left) {
        if (!root) {
            return 0;
        }
        if (is_left) {
            if (!root->left && !root->right) {
                return root->val;
            }
        }
        return sumOfChild(root->left, true) + sumOfChild(root->right, false);
    }
};
