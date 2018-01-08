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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *p = head, *prev = new ListNode(0);
        ListNode *prehead = prev;
        prev->next = head;
        while (p) {
            if (p->val != val) {
                prev->next = p;
                prev = p;
                p = p->next;
            } else {
                p = p->next;
            }
        }
        prev->next = NULL;
        return prehead->next;
    }
};
