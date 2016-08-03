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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) {
            return NULL;
        }
        if (len == 1) {
            return new TreeNode(nums[0]);
        }

        int mid = len / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left;
        vector<int> right;

        left.resize(mid);
        right.resize(len-1-mid);

        if (mid != 0) {
            std::copy(nums.begin(), nums.begin()+mid, left.begin());
            root->left = sortedArrayToBST(left);
        }

        if (mid != len - 1) {
            std::copy(nums.begin()+mid+1, nums.end(), right.begin());
            root->right = sortedArrayToBST(right);
        }

        return root;
    }
};
