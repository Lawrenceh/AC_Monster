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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *p = head, *l = left, *r = right;
        while (p) {
            if (p->val < x) {
                l->next = p;
                l = l->next;
            } else {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        l->next = right->next;
        r->next = NULL; // need to remove the pointer from the last right node
        return left->next;
        
    }
};
