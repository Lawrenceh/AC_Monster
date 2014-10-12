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
    while (!s.empty() || node != NULL) {
        if (node != NULL) { // travese to the left child
            s.push(node);
            node = node->left;
        } else {
            node = s.pop();
            visit(node);
            node = node -> right;
        }
    }
}

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
