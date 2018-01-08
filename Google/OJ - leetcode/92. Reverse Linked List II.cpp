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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !(head->next)) return head;
        ListNode *p = head, *prev = NULL;
        while (m > 1) {
            m --;
            n --;
            prev = p;
            p = p->next;
        }
        ListNode *next, *prehead = NULL;
        while (n-- > 0) {
            next = p->next;
            p->next = prehead;
            prehead = p;
            p = next;
        }
        // two cases: whether head is in reversed node list or not
        if (prev) {
            prev->next->next = p;
            prev->next = prehead;
            return head;
        } else {
            head->next = p;
            return prehead;
        }
    }
};
