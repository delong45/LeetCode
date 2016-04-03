class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0; 
        int left = getLeftHeight(root);
        int right = getRightHeight(root);
        if (left == right) {
            return (1 << left) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
private:
    int getLeftHeight(TreeNode *root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

    int getRightHeight(TreeNode *root) {
        int height = 0;
        while (root) {
            root = root->right;
            height++;
        }
        return height;
    }
};
