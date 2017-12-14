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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *curr = head;
        ListNode *prev, *p, *q;
        ListNode *ph = new ListNode(0);
        ph->next = head;
        while (curr->next) {
            q = curr;
            curr = curr->next;
            prev = ph;
            p = prev->next;
            while (p->val <= curr->val && p != curr) {
                prev = p;
                p = p->next;
            }
            q->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            if (curr != p) curr = q;
        }
        return ph->next;
    }
};
