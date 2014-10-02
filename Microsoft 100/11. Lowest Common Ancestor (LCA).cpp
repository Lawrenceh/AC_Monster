// with parent ptr
Node * NearestCommonAncestor(Node * root,Node * p,Node * q) {
	Node * temp;
    while(p!=NULL) {
        p=p->parent;
        temp=q;
        while(temp!=NULL) {
            if(p==temp->parent)
                return p;
            temp=temp->parent;
        }
    }
}

// without parent ptr
// two cases in the layout: one-sided or two-sided
typedef struct BiTNode {  
    char data;
    struct BiTNode *lchild, *rchild;      
} BinaryTreeNode; 

BinaryTreeNode* findLowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b) {
    if (root == NULL) return NULL;
    if (root == a || root == b) return root;
    BinaryTreeNode* left = findLowestCommonAncestor(root->lchild, a, b);
    BinaryTreeNode* right = findLowestCommonAncestor(root->rchild, a, b);
    if (left && right) return root;
    return left ? left : right;
}

// binary search tree, with root and the value at a and b
BinaryTreeNode* findLowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b) {
    char min, max;
    if (a->data < b->data) min = a->data, max = b->data;
    else min = b->data, max = a->data;
    while (root) {
        if (root->data >= min && root->data <= max) return root;
        else if (root->data < min && root->data < max) root = root->rchild;
        else root = root->lchild;
    }
    return NULL;
}
