/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode *root, int sum, int psum, vector<int> paths, vector<vector<int>> &result){
    psum += root->val;
    paths.push_back(root->val);

    if(!root->left && !root->right && sum == psum){
        result.push_back(paths);
    }

    if(root->left)
        dfs(root->left, sum, psum, paths, result);
    if(root->right)
        dfs(root->right, sum, psum, paths, result);

}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int>paths;
        if(!root)
            return result;
        int psum = 0;
        dfs(root, sum, psum, paths, result);
        return result;
    }
};
