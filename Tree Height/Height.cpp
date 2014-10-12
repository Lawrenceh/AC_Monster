struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 struct denode  
{  
    TreeNode* node;  
    int degree;  
};  
class Solution {
    public:
        int maxDepth(TreeNode *root) {

            if(root==NULL)return 0;  
            queue<denode> que;  

            denode dnode;  
            dnode.degree=1;  
            dnode.node=root;  

            que.push(dnode);  

            int degree=1;  
            while(!que.empty())  {  
                denode ptr=que.front();  
                que.pop();  

                degree=ptr.degree;  

                if(ptr.node->left!=NULL)  {  
                    denode p;  
                    p.node=ptr.node->left;  
                    p.degree=ptr.degree+1;  
                    que.push(p);  
                }  

                if(ptr.node->right!=NULL)  {  
                    denode p;  
                    p.node=ptr.node->right;  
                    p.degree=ptr.degree+1;  
                    que.push(p);  
                }  
            }  
            return degree;   
        }
};
