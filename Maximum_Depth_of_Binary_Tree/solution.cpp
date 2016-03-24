class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 1;  
        depth += max(maxDepth(root->left), maxDepth(root->right));
        return depth;
    }
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};
