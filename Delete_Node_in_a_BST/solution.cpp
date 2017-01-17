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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            if (root->left) {
                TreeNode *parent = root;
                TreeNode *p = root->left;
                while (p->right) {
                    parent = p;
                    p = p->right;
                }
                if (p == root->left) {
                    p->right = root->right;
                    free(root);
                    root = p;
                    return root;
                } else {
                    parent->right = p->left;
                    p->left = root->left;
                    p->right = root->right;
                    free(root);
                    root = p;
                    return root;
                }
            } else if (root->right) {
                TreeNode *parent = root;
                TreeNode *p = root->right;
                while (p->left) {
                    parent = p;
                    p = p->left;
                }
                if (p == root->right) {
                    p->left = root->left;
                    free(root);
                    root = p;
                    return root;
                } else {
                    parent->left = p->right;
                    p->left = root->left;
                    p->right = root->right;
                    free(root);
                    root = p;
                    return root;
                }
            } else {
                return NULL;
            }
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
