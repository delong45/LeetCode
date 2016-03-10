class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newList = new ListNode(0);
        ListNode* p = newList;
        vector<ListNode*> greater;

        ListNode* node = head;
        while (node) {
            if (node->val < x) {
                p->next = node;
                p = p->next;
            } else {
                greater.push_back(node);
            }
            node = node->next;
        }

        for (int i = 0; i < greater.size(); i++) {
            p->next = greater[i];
            p = p->next;
        }
        p->next = NULL;
        return newList->next;
    }
};
