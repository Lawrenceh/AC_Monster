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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head->next, *q = dummy;
        int val = head->val;
        bool flag = false;
        while (p) {
            if (p->val == val) {
                p = p->next;
                flag = true;
            } else {
                if (!flag) {
                    q = q->next;
                } else {
                    q->next = p;
                    flag = false;
                }
                val = p->val;
                p = p->next;
            }
        }
        if (flag) q->next = NULL;
        return dummy->next;
    }
};
