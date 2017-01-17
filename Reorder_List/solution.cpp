/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }            
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        reorder(head, tail);
    }
private:
    ListNode* reorder(ListNode* head, ListNode* tail) {
        if (!head || !head->next) {
            return head;
        }
        if (head->next == tail) {
            tail->next = NULL;
            return head;
        }
        if (head == tail) {
            return head;
        }

        ListNode* new_tail = head;
        while (new_tail->next != tail) {
            new_tail = new_tail->next;
        }
        new_tail->next = NULL;

        ListNode* new_next = head->next;
        head->next = tail;
        tail->next = reorder(new_next, new_tail);
        return head;
    }
};
