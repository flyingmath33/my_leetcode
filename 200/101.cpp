/*
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
  For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
  But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
  Note:
  Bonus points if you could solve it both recursively and iteratively.
*/

bool check_symmetric(TreeNode *p, TreeNode *q)
    {
        return ((p == NULL && q == NULL) || 
                (p != NULL &&
                 q != NULL &&
                 p->val == q->val &&
                 check_symmetric(p->left, q->right) &&
                 check_symmetric(p->right, q->left)));
        
    }

    bool isSymmetric(TreeNode* root) {
            return (root == NULL || check_symmetric(root->left, root->right));
    }

bool isSymmetricAux(TreeNode *l, TreeNode *r)
{
        if((l == NULL && r == NULL) ||
	   (l != NULL && r != NULL && l->val == r->val &&
	    isSymmetricAux(l->left, r->right) &&
	    isSymmetricAux(l->right, r->left)))
	   return true;
	   
    	return false;
}
    
bool isSymmetric(TreeNode* root) {
        if(!root)
    		return true;
    
    	return isSymmetricAux(root->left, root->right);
}
