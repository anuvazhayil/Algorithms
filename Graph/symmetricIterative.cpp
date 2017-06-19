/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode *u, *v;

        if(root == NULL)
            return true;
        else if(root->left == NULL && root->right == NULL)
            return true;
        else if((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
            return false;
        else{
            q.push(root->left);
            q.push(root->right);
        }

        while(!q.empty()){
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if(u->val != v->val)
                return false;
            else{
                if(u->left && !v->right || !u->left && v->right)
                    return false;

                if(u->left && v->right){
                    q.push(u->left);
                    q.push(v->right);
                }

                if(u->right && !v->left || !u->right && v->left)
                    return false;

                if(u->right && v->left){
                    q.push(u->right);
                    q.push(v->left);
                }
            }

        }
        return true;
    }
};
