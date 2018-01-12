/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // use next pointer along with level order traversal
        TreeLinkNode *node = root, *prev = nullptr, *head = nullptr;
        while (node) {
            while (node) {
                if (node->left) {
                    if (!head) head = node->left;
                    if (prev) prev->next = node->left;
                    prev = node->left;
                }
                if (node->right) {
                    if (!head) head = node->right;
                    if (prev) prev->next = node->right;
                    prev = node->right;
                }
                node = node->next;
            }
            node = head;
            head = nullptr;
            prev = nullptr;
        }
    }
};
