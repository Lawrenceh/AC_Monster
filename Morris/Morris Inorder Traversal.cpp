/* Function to traverse binary tree without recursion and without stack */
vector<int> inorderTraversal(TreeNode *root) {
       vector<int> result;  
       TreeNode  *current,*pre;
       if(root == NULL)
       return result;
       current = root;
       while(current != NULL) {                
             if(current->left == NULL) {
                    result.push_back(current->val);
                    current = current->right;     
             } else {
                 /* Find the inorder predecessor of current */
                 pre = current->left;
                 while(pre->right != NULL && pre->right != current) pre = pre->right; 
                 /* Make current as right child of its inorder predecessor */
                 if(pre->right == NULL) {
                     pre->right = current;
                     current = current->left;
                 }
                 /* Revert the changes made in if part to restore the original
                    tree i.e., fix the right child of predecssor */  
                 else {
                     pre->right = NULL;
                     result.push_back(current->val);
                     current = current->right;     
                 } /* End of if condition pre->right == NULL */
             } /* End of if condition current->left == NULL*/
       } /* End of while */
       return result;
}
