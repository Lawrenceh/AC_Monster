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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newHead = NULL, *cur = head, *p = head, *q = NULL;
        if (head == NULL || head->next == NULL) return head;
        while (p != NULL) {
            cur = p;
            p = p->next;
            if (newHead == NULL) {
                newHead = head;
                newHead->next = NULL; // DIVIDE THE TWO PART BY "NULL"
            } else if (cur->val < newHead->val) {
                cur->next = newHead;
                newHead = cur;
            } else {
                q = newHead;
                while (q != NULL) {
                    if (q->next == NULL || q->next->val > cur->val) {
                        cur->next = q->next;
                        q->next = cur;
                        break;
                    }
                    q = q->next;
                }
            }
        }
        return newHead;
    }
};
