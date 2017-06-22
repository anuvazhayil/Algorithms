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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        unordered_map<int, vector<int>>level_map;
        queue<pair<TreeNode*, int>>q;

        if(!root)
            return result;

        q.push(make_pair(root, 0));
        pair<TreeNode*, int> curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();

            level_map[curr.second].push_back(curr.first->val);

            if(curr.first->left)
                q.push(make_pair(curr.first->left, curr.second+1));
            if(curr.first->right)
                q.push(make_pair(curr.first->right, curr.second+1));

        }

        for(int i = 0; i < level_map.size(); i++){
            if(i % 2){
                reverse(level_map[i].begin(), level_map[i].end());
                result.push_back(level_map[i]);
            }
            else{
                result.push_back(level_map[i]);
            }
        }
        return result;
    }
};
