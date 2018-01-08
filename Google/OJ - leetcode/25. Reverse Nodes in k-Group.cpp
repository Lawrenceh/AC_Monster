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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        int cnt = k;
        ListNode *p = head, *prev, *next;
        while (cnt > 0 && p) {
            p = p->next;
            cnt --;
        }
        if (cnt > 0) return head;
        else {
            cnt = k;
            p = head->next;
            prev = head;
            while (--cnt > 0) {
                next = p->next;
                p->next = prev;
                prev = p;
                p = next;
            }
            ListNode *nhead = reverseKGroup(p, k);
            head->next = nhead;
            return prev;
        }
    }
};
