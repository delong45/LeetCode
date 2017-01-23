class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode *h = head;
        ListNode *q = head;
        ListNode *p = head->next;
        while (p) {
            if (p->val == q->val) {
                q->next = NULL;
            } else if (q->next != p){
                q->next = p;
                q = q->next;
            } else{
                q = q->next;
            }
            p = p->next;
        }
        return h;
    }
};
