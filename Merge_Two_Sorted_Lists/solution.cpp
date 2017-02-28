/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (l1 && !l2) return l1;
        if (!l1 && l2) return l2;

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = NULL;
        ListNode *p = NULL;

        while (p1 && p2) {
            int val = 0;
            if (p1->val <= p2->val) {
                val = p1->val;
                p1 = p1->next;
            } else {
                val = p2->val;
                p2 = p2->next;
            }
            if (!head) {
                head = new ListNode(val);
                p = head;
            } else {
                ListNode *node = new ListNode(val);
                p->next = node;
                p = p->next;
            }
        }

        while (p1) {
            p->next = new ListNode(p1->val);
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            p->next = new ListNode(p2->val);
            p = p->next;
            p2 = p2->next;
        }

        return head;
    }
};
