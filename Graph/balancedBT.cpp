/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode *root){
    if(!root)
        return 0;
    return max(dfs(root->left), dfs(root->right)) +1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int l = dfs(root->left);
        int r = dfs(root->right);

        int diff = abs(l-r);
        return ((diff <= 1) && isBalanced(root->left) && isBalanced(root->right));
    }
};
