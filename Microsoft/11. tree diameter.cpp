// tree diameter
static int tree_height(const Node *root, int &max_distance) {
    const int left_height = root -> left ? tree_height(root->left, max_distance)  + 1 : 0;
    const int right_height = root -> right ? tree_height(root->right, max_distance)  + 1 : 0;
    const int distance = left_height + right_height;
    if (max_distance < distance) max_distance = distance;
    return (left_height > right_height ? left_height : right_height);
}

int tree_diameter(const Node *root) {
    int max_distance = 0;
    if (root) tree_height(root, max_distance);
    return max_distance;
}

// balanced binary tree check
static int tree_height(const Node* root, bool& balanced) {
    const int left_height = root->left ? tree_height(root->left, balanced) + 1 : 0;
    if (!balanced) return 0;

    const int right_height = root->right ? tree_height(root->right, balanced) + 1 : 0;
    if (!balanced) return 0;

    const int diff = left_height - right_height;
    if (diff < -1 || diff > 1) balanced = false; 
    return (left_height > right_height ? left_height : right_height);
}

bool is_balanced_tree(const Node* root) {
    bool balanced = true;
    if (root) tree_height(root, balanced);
    return balanced;
}

