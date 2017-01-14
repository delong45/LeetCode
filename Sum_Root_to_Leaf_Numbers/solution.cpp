/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return root->val;
        }

        int sum = 0;
        if (root->left) {
            vector<string> ls = sumTree(root->left);
            for (int i = 0; i < ls.size(); i++) {
                string n = to_string(root->val) + ls[i];
                sum += stoi(n);
            }
        }
        if (root->right) {
            vector<string> rs = sumTree(root->right);
            for (int i = 0; i < rs.size(); i++) {
                string n = to_string(root->val) + rs[i];
                sum += stoi(n);
            }
        }
        return sum;
    }
private:
    vector<string> sumTree(TreeNode* root) {
        vector<string> ret;
        if (!root->left && !root->right) {
            ret.push_back(to_string(root->val));
            return ret;
        }
        if (root->left) {
            vector<string> ls = sumTree(root->left);
            for (int i = 0; i < ls.size(); i++) {
                ret.push_back(to_string(root->val)+ls[i]);
            }
        }
        if (root->right) {
            vector<string> rs = sumTree(root->right);
            for (int i = 0; i < rs.size(); i++) {
                ret.push_back(to_string(root->val)+rs[i]);
            }
        }
        return ret;
    }
};
