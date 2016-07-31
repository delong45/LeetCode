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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vv;
        if (root == NULL) {
            return vv;
        }

        vector<int> v;
        path(root, sum, v, vv);
        return vv;
    }
private:
    void path(TreeNode* root, int sum, vector<int> &v, vector<vector<int>> &vv) {
        v.push_back(root->val);
        sum -= root->val;
        if (root->left || root->right) {
            if (root->left) {
                path(root->left, sum, v, vv);
            }
            if (root->right) {
                path(root->right, sum, v, vv);
            }
        } else if (sum == 0) {
            vv.push_back(v);
        }
        v.pop_back();
    }
};
