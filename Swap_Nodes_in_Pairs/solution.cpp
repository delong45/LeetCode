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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        ListNode* next_head = NULL;
        if (head->next) {
            next_head = head->next->next;
            head->next->next = head;
            head = head->next;
            head->next->next = swapPairs(next_head);
        }
        return head;
    }
};
