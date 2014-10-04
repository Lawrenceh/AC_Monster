// recursive
void preorderRecursive(TreeNode *node) {
    if (node == NULL) return;
    visit(node);
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}

// non-recursive
void preorder(TreeNode *node) {
    stack<TreeNode *> s;
    s.push(node);
    while (!s.empty()) {
        TreeNode *n = s.pop();
        visit(n);
        if (n->right != NULL) s.push(n->right);
        if (n->left != NULL) s.push(n->left);
    }
}

void inorder(TreeNode *node) {
    stack<TreeNode *> s;
    TreeNode *cur;
    while (!s.empty() || cur != NULL) {
        if (cur != NULL) {
            s.push(cur);
            cur = cur -> left;
        } else {
            visit(s.pop());
            cur = cur -> right;
        }
    }
}

// postorder with two stacks
void postorder(TreeNode *node) {
    stack<TreeNode *> s1, s2;
    s1.push(node);
    while (!s1.empty()) {
        TreeNode *p = s1.pop();
        s2.push(p);
        if (p->left != NULL) s1.push(p->left);
        if (p->right != NULL) s1.push(p->right);
    }
    while (!s2.empty()) visit(s2.pop());
}
