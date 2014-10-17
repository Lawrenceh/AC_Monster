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
    ListNode* reverse(ListNode *node) {
        if (node == NULL || node->next == NULL) return node;
        ListNode *prev, *curr, *p;
        prev = curr = node; p = node->next;
        while (p != NULL) {
            curr = p;
            p = p->next;
            curr->next = prev;
            prev = curr;
        }
        node->next = NULL;
        return curr;
    }
    void f(ListNode *node) {
        ListNode *slow, *fast, *head, *p, *q, *next;
        fast = slow = node;
        while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        head = reverse(slow->next);
        slow->next = NULL;
        p = node; q = head; next = node;
        while (q != NULL) {
            next = p->next;
            p->next = q;
            q = q->next;
            p->next->next = next;
            p = next;
        }
        if (p != NULL) p->next = NULL;
    }
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        f(head);
    }
};
