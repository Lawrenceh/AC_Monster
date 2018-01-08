/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        // create map
        while (p) {
            mp[p] = new RandomListNode(p->label);
            p = p->next;
        }
        // assign next and random pointers
        p = head;
        while (p) {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        return mp[head];
    }
};
