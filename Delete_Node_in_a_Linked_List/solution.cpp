class Solution {
public:
    void deleteNode(ListNode *node) {
        if (node->next) {
            node->val = node->next->val;
            node->next = node->next->next;
        } else {
            node = NULL;
        }
    }
};
