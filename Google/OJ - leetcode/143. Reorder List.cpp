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
    ListNode* reorder(ListNode *head, bool flag) {
        if (!head) return head;
        if (flag) {
            head->next = reorder(head->next, !flag);
            return head;
        } else {
            ListNode *p = head, *prev = NULL;
            while (p->next) {
                prev = p;
                p = p->next;
            }
            if (prev) {
                prev->next = NULL;
                p->next = reorder(head, !flag);
                return p;
            } else {
                return head;
            }
        }
    }
    void reorderList(ListNode* head) {
        reorder(head, true);
    }
};
