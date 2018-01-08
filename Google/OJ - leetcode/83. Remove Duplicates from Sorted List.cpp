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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *p = head->next, *q = head;
        int val = head->val;
        while (p) {
            if (p->val == val) {
                p = p->next;
            } else {
                val = p->val;
                q->next = p;
                q = q->next;
                p = p->next;
            }
        }
        q->next = NULL;
        return head;
    }
};
