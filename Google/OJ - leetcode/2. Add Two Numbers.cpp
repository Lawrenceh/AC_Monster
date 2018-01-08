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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode node(0);
        ListNode *head = &node;
        ListNode *p = head;
        while (l1 || l2) {
            if (l1 == NULL) {
                if (carry + l2->val > 9) {
                    p->next =  new ListNode(0);
                    carry = 1;
                } else {
                    p->next = new ListNode(carry + l2->val);
                    carry = 0;
                }
                p = p->next;
                l2 = l2->next;
            } else if (l2 == NULL) {
                if (carry + l1->val > 9) {
                    p->next =  new ListNode(0);
                    carry = 1;
                } else {
                    p->next = new ListNode(carry + l1->val);
                    carry = 0;
                }
                p = p->next;
                l1 = l1->next;
            } else {
                if (carry + l1->val + l2->val > 9) {
                    p->next = new ListNode(carry + l1->val + l2->val - 10);
                    carry = 1;
                } else {
                    p->next = new ListNode(carry + l1->val + l2->val);
                    carry = 0;
                }
                p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (carry) {
            p->next = new ListNode(1);
        }
        return head->next;
    }
};
