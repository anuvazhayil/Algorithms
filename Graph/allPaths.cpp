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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(!root)
            return result;
        queue<pair<TreeNode*, string>>q;
        q.push(make_pair(root, to_string(root->val)));
        pair<TreeNode*, string>curr;
        while(!q.empty()){
            curr = q.front();  q.pop();
            if(curr.first->left){
                q.push(make_pair(curr.first->left, curr.second + "->" + to_string(curr.first->left->val)));
            }
            if(curr.first->right){
                q.push(make_pair(curr.first->right, curr.second + "->" + to_string(curr.first->right->val)));
            }
            if(!curr.first->left && !curr.first->right){
                result.push_back(curr.second);
            }
        }
        return result;
    }
};/**
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(!root)
            return result;
        queue<pair<TreeNode*, string>>q;
        q.push(make_pair(root, to_string(root->val)));
        pair<TreeNode*, string>curr;
        while(!q.empty()){
            curr = q.front();  q.pop();
            if(curr.first->left){
                q.push(make_pair(curr.first->left, curr.second + "->" + to_string(curr.first->left->val)));
            }
            if(curr.first->right){
                q.push(make_pair(curr.first->right, curr.second + "->" + to_string(curr.first->right->val)));
            }
            if(!curr.first->left && !curr.first->right){
                result.push_back(curr.second);
            }
        }
        return result;
    }
};
