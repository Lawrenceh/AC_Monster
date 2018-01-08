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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode *nhead = head->next;
        ListNode *p = head->next->next;
        head->next->next = head;
        head->next = swapPairs(p);
        return nhead;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /* ---pp is the pointer to pointer a---> a -> b -> (b->next) */
        /* pp == b -> a ----pp now is pointer to the start of next two--> (b->next) */
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            /* NOTE: use *p = head won't work below because p = b won't redirect head to b. It would only update p instead of head */
            /* e.g. p = a->next, we want to change a->next address, we cannot do p = b because it is another pointer to this addr */
            a->next = b->next;
            b->next = a;
            *pp = b; // update after-swap head pointer position
            pp = &(a->next); // re-point pp towards the following list
        }
        return head;
    }
};
