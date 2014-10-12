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
    void split(ListNode *node, ListNode **a, ListNode **b) {
        if (node == NULL) return;
        if (node->next == NULL) {
            *a = node;
            *b = NULL;
            return;
        }
        ListNode *p1, *p2;
        p1 = p2 = node;
        while (p1->next != NULL && p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        *a = node;
        *b = p1->next;
        // important
        p1->next = NULL;
    }
    ListNode *doMerge(ListNode *a, ListNode *b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        if (a->val < b->val) {
            a->next = doMerge(a->next, b);
            return a;
        } else {
            b->next = doMerge(a, b->next);
            return b;
        }
    }
    void merge(ListNode **node) {
        if (*node == NULL || (*node)->next == NULL) return;
        ListNode *a, *b;
        split(*node, &a, &b);
        merge(&a);
        merge(&b);
        *node = doMerge(a, b);
    }
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return NULL;
        merge(&head);
        return head;
    }
};
