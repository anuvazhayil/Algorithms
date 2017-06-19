/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool recIsSymmetric(TreeNode* u, TreeNode* v){
    if(u == NULL && v == NULL)
        return true;
    else if((u == NULL && v != NULL) || (v== NULL && u != NULL))
        return false;
    else if( u->val != v->val)
        return false;
    else if(u->val == v->val)
        return (recIsSymmetric(u->left, v->right) && recIsSymmetric(u->right, v->left));
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return recIsSymmetric(root->left, root->right);
    }
};
