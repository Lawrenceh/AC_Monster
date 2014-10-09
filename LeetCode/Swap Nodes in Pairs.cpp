// recursive version
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head||!head->next)  return head;
        ListNode *reverse_head = head->next;
        ListNode *next_pair_head = reverse_head->next;
        reverse_head->next = head;
        head->next = swapPairs(next_pair_head);
        return reverse_head;
    }
};

// non-recursive version BF
ListNode *swapPairs(ListNode *head) {
    if(head == nullptr)
        return nullptr;
    ListNode *base = head->next != nullptr ? head->next : head;
    ListNode *currPairFirst = head, *currPairSecond = head->next, *prevPairSecond = nullptr;
    while(currPairFirst != nullptr &&  currPairSecond != nullptr) {
        ListNode *nextPairFirst = currPairSecond->next;
        currPairSecond->next = currPairFirst; 
        currPairFirst->next = nextPairFirst; 
        if(prevPairSecond != nullptr)
            prevPairSecond->next = currPairSecond;
        prevPairSecond = currPairFirst;
        if(nextPairFirst == nullptr)
            break;
        currPairFirst = nextPairFirst;
        currPairSecond = nextPairFirst->next;
    }
    return base;
}

// non-recursive version DOUBLE POINTER
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;

        while (*p && (*p)->next) {
            ListNode *t = (*p)->next;

            (*p)->next = t->next;
            t->next = *p;
            *p = t; // adjust the temporary wrong pointer

            p = &(*p)->next->next; // make p point the pointer to the unprocessed first node! (just like pointing to the head node)
        }

        return head;
    }
};
