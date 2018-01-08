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
    ListNode *detectCycle(ListNode *head) {
        /* below code fails at one node no cycle cases! because slow starts as the same addr as fast */
        /*
        if (!head) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        if (fast != slow) return NULL;
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        */
        if (!head) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) { // cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            };
        }
        return NULL;
    }
};
