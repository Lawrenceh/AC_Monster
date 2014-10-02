#include <iostream>
using namespace std;

struct BSTreeNode {
    int value;
    BSTreeNode *left;
    BSTreeNode *right;
}

BSTreeNode *treeToLinkedList(BSTreeNode *root) {
    BSTreeNode *head, *tail;
    f(head, tail, root);
    return head;
}

void f(BSTreeNode *&head, BSTreeNode *&tail, BSTreeNode *root) {
    BSTreeNode *lt, *rh;
    if (root == NULL) {
        head = NULL; tail = NULL; return;
    }
    f(head, lt, root->left);
    f(rh, tail, root->right);
    if (lt != NULL) {
        lt->right = root;
        root->left = lt;
    } else {
        head = root;
    }
    if (rh != NULL) {
        rh->left = root;
        root->right = rh;
    } else {
        tail = root;
    }
}

int main() {return 0;}

