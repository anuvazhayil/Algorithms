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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        queue<pair<TreeNode*, int>>q;
        vector<int>temp(0);

        if(!root)
            return result;

        q.push(make_pair(root, 0));
        pair<TreeNode*, int> curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();

            if(result.size() == curr.second)
                result.push_back(temp);

            result[curr.second].push_back(curr.first->val);

            if(curr.first->left)
                q.push(make_pair(curr.first->left, curr.second+1));
            if(curr.first->right)
                q.push(make_pair(curr.first->right, curr.second+1));
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
