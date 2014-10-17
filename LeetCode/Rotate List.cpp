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
    ListNode *reverse(ListNode *node) {
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;
        if (k == 0) return head;
        head = reverse(head);
        ListNode *newHead = head, *prev = head;
        while (k > 0) {
            if (newHead == NULL) {
                newHead = head;
                prev = head;
                continue;
            }
            prev = newHead;
            newHead = newHead->next;
            -- k;
        }
        prev->next = NULL;
        prev = head;
        head = reverse(head);
        newHead = reverse(newHead);
        prev->next = newHead;
        return head;
    }
};
