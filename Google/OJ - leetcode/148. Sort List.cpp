class Solution {
public:
    /* non-recursive merge + 2-hop check next
    ListNode* merge(ListNode *p, ListNode *q) {
        ListNode* head, *curr;
        if (!p) return q;
        if (!q) return p;
        if (p->val < q->val) {
            head = p;
            p = p->next;
        } else {
            head = q;
            q = q->next;
        }
        curr = head;
        while (p && q) {
            if (p->val < q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (!p) curr->next = q;
        else curr->next = p;
        return head;
        
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* p1, *p2;
        p1 = p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* h = p1->next;
        p1->next = NULL;
        ListNode* h1, *h2;
        h1 = sortList(head);
        h2 = sortList(h);
        return merge(h1, h2);
    }
    */

    /* recursive merge + 1-hop next w/ a prev pointer
     * seems to be simpler
     */
    ListNode* merge(ListNode *p, ListNode *q) {
        if (!p) return q;
        if (!q) return p;
        if (p->val < q->val) {
            p->next = merge(p->next, q);
            return p;
        } else {
            q->next = merge(q->next, p);
            return q;
        }
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p0, *p1, *p2;
        p0 = p1 = p2 = head;
        while (p2 && p2->next) {
            p0 = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p0->next = NULL;
        ListNode *h1 = sortList(head);
        ListNode *h2 = sortList(p1);
        return merge(h1, h2);
    }
};
