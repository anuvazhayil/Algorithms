/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findSum(TreeNode *root, int num, int &sum){
    num *= 10;
    num += root->val;
    if(!root->left && !root->right)
        sum += num;
    if(root->left)
    	findSum(root->left, num, sum);
    if(root->right)
    	findSum(root->right, num, sum);
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int num = 0, sum = 0;
        findSum(root, num, sum);
        return sum;
    }
};
