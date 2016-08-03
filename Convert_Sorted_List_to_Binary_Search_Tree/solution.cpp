/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }

        if (!head->next) {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *mid = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            if (slow != mid) {
                slow = slow->next;
            }
            mid = mid->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(mid->val);
        if (slow != mid) {
            slow->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(mid->next);

        return root;
    }
}
