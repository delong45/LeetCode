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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left) {
            flatten(left);
        }
        if (right) {
            flatten(right);
        }
        root->left = NULL;
        root->right = left;
        while (root->right) {
            root = root->right;
        }
        root->right = right;
    }
};
