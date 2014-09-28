/* The key is use backtracking and recursion IF YOU USE REFERENCE
 * Or you can just use recursion to deal with the problem
 */

void f(TreeNode *root, int &sum, int path[], int &top) {
    path[top ++] = root.data;
    sum -= root.data;
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) printPath(path, top);
    } else {
        if (root->left != NULL) f(root->left, sum, path, top);
        if (root->right != NULL) f(root->right, sum, path, top);
    }
    top --;
    sum += root.data;
}
