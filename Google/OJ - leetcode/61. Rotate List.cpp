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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode *p = head;
        int n = 0;
        while (p) {
            ++n;
            p = p->next;
        }
        k %= n;
        if (!k) return head;
        k = n - k;
        p = head;
        while (--k) p = p->next;
        ListNode *q = p;
        p = p->next;
        q->next = NULL;
        q = p;
        while (p->next) p = p->next;
        p->next = head;
        return q;
    }
};
