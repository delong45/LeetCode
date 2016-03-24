class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 1;
        if (root->left && root->right) {
            depth += min(minDepth(root->left), minDepth(root->right));
        } else if (root->left) {
            depth += minDepth(root->left);
        } else if (root->right) {
            depth += minDepth(root->right);
        } else {
            return depth;
        }
        return depth;
        
    }
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
};
