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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare > h;
        // make heap
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i]) h.push(lists[i]);
        }
        if (h.empty()) return NULL;
        ListNode *result = h.top();
        h.pop();
        if (result->next) h.push(result->next);
        ListNode *p = result;
        while (!h.empty()) {
            p->next = h.top();
            h.pop();
            p = p->next;
            if (p->next) h.push(p->next);
            
        }
        return result;
    }
};
