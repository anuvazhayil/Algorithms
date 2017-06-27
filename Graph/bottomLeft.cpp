/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root, int level, pair<int,int> &leftmost){
    if(!root->left && !root->right && level > leftmost.first){
        leftmost = make_pair(level, root->val);
    }
    if(root->left)
        dfs(root->left, level+1, leftmost);
    if(root->right)
        dfs(root->right, level+1, leftmost);
}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int>leftmost(make_pair(0, root->val));
        dfs(root, 0, leftmost);
        return leftmost.second;
    }
};
