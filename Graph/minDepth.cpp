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
    int minDepth(TreeNode* root) {

        if(!root)
            return 0;

        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root, 1));
        pair<TreeNode*, int> curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(!curr.first->right && !curr.first->left)
                return curr.second;
            if(curr.first->left)
                q.push(make_pair(curr.first->left, curr.second+1));
            if(curr.first->right)
                q.push(make_pair(curr.first->right, curr.second+1));
        }
    }
};
