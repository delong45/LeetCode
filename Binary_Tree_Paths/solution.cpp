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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;    
        if (!root) {
            return v;
        }
        paths(root, v, to_string(root->val));
        return v;
    }
private:
    void paths(TreeNode* root, vector<string>& v, string t) {
        if (!root->left && !root->right) {
            v.push_back(t);
            return;
        }

        if (root->left) {
            paths(root->left, v, t + "->" + to_string(root->left->val));
        }
        if (root->right) {
            paths(root->right, v, t + "->" + to_string(root->right->val));
        }
    }
};
