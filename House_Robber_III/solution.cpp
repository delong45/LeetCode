class Solution {
public:
    int rob(TreeNode* root) {
        int result = 0;
        if (!root) {
            return result;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }

        result = root->val;
        if (root->left && root->left->left) {
            result += rob(root->left->left);
        }
        if (root->left && root->left->right) {
            result += rob(root->left->right);
        }
        if (root->right && root->right->left) {
            result += rob(root->right->left);
        }
        if (root->right && root->right->right) {
            result += rob(root->right->right);
        }

        int childResult = 0;
        if (root->left) {
            childResult += rob(root->left);
        }
        if (root->right) {
            childResult += rob(root->right);
        }

        result = result > childResult ? result : childResult;
        return result;
    }
};
