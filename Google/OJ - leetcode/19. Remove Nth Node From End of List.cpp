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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2, *prev;
        p1 = p2 = head;
        while (--n > 0) {
            p1 = p1->next;
        }
        while (p1->next) {
            prev = p2;
            p2 = p2->next;
            p1 = p1->next;
        }
        // p2 at removal
        if (p2 == head) return head->next;
        else {
            prev->next = p2->next;
            return head;
        }
    }
};
