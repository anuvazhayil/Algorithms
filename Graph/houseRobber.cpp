/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> maxMoney(TreeNode *root){
    if(!root)
        return vector<int>(2);

    vector<int>res(2), left(2), right(2);
    left = maxMoney(root->left);
    right = maxMoney(root->right);

    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];
    return res;
}
class Solution {
public:
    int rob(TreeNode* root) {

        vector<int> res(2);
        res = maxMoney(root);
        return (res[0] > res[1])? res[0] : res[1];
    }
};
