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
        ListNode *p = head, *next, *prev = NULL;
        while (p) {
            next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = reverseList(slow->next);
        while (p) {
            if (head->val != p->val) return false;
            head = head->next;
            p = p->next;
        }
        return true;
    }
};
