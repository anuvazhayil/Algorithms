/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//pos = 0 for left, pos = 1 for right
bool inorderCheck(TreeNode *curr, TreeNode* &prev){
    if(!curr)
        return true;
    if(!inorderCheck(curr->left, prev))
        return false;
    if(prev && prev->val >= curr->val)
        return false;
    prev = curr;
    return inorderCheck(curr->right, prev);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        bool res = inorderCheck(root, prev);
        return res;
    }
};
