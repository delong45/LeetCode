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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) < 2) {
            return true;
        }
        return false;
    }
private:
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
