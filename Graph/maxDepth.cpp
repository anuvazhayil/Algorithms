/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* root, int count, int &max_count){
    if(!root->left && !root->right){
        if(count > max_count)
            max_count = count;
    }
    if(root->left){
        dfs(root->left, count+1, max_count);
    }
    if(root->right){
        dfs(root->right, count+1, max_count);
    }
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int max_count = 1;
        dfs(root, 1, max_count);
        return max_count;
    }
};
