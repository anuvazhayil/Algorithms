/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse(TreeNode *root, int level, unordered_map<int, list<int>> &nodes_level){
    nodes_level[level].push_back(root->val);
    if(root->left)
        traverse(root->left, level+1, nodes_level);
    if(root->right)
        traverse(root->right, level+1, nodes_level);
}
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int, list<int>>nodes_level;
        if(!root)
            return vector<int>();
        traverse(root, 0, nodes_level);

        vector<int>result(nodes_level.size());
        for(auto ele: nodes_level){
            int max = ele.second.front();
            for(auto nodes: ele.second){
                if(nodes > max)
                    max = nodes;
            }
            result[ele.first] = max;
        }
        return result;
    }
};
