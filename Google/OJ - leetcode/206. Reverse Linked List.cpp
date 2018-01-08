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
    ListNode* reverseList(ListNode* head) {
        /* recursive
        if (!head || !(head->next)) return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
        */
        /* iterative: iterating one node by another */
        ListNode *prehead = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prehead;
            prehead = head;
            head = next;
        }
        return prehead;
    }
};
