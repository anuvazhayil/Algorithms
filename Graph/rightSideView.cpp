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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        queue<TreeNode*>q;
        TreeNode* curr;
        if(!root)
            return result;

        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                curr = q.front();
                q.pop();
                if(i == len-1){
                    result.push_back(curr->val);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }

        return result;
    }
};
