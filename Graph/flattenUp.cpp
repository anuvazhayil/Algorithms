/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flattenUp(TreeNode *root, TreeNode* &prev){
    if(!root){
        return;
    }
    flattenUp(root->right, prev);
    flattenUp(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *prev = NULL;
        flattenUp(root, prev);
    }
};
