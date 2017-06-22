/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode* root, int sum, int tsum){
    tsum += root->val;
    if(!root->right && !root->left && tsum == sum){
        return true;
    }
    if(root->left){
        if(dfs(root->left, sum, tsum))
            return true;
    }
    if(root->right){
        if(dfs(root->right, sum, tsum))
            return true;
    }
    return false;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int tsum = 0;
        if(!root)
            return false;
        bool result = dfs(root, sum, tsum);
        return result;
    }
};
