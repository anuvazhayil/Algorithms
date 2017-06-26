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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(!preorder.size())
            return NULL;

        stack<int>sv;
        stack<TreeNode*>sn;
        int i = 1, j = 0, ins_right = 0;

        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *temp = root;
        sv.push(preorder[0]);
        sn.push(root);

        while(i < preorder.size()){
            if(!sv.empty() && sv.top() == inorder[j]){
                ins_right = 1;
                sv.pop();
                temp = sn.top();
                sn.pop();
                ++j;
            }
            else{
                if(ins_right){
                    ins_right = 0;
                    sv.push(preorder[i]);
                    TreeNode *curr = new TreeNode(preorder[i]);
                    temp->right = curr;
                    temp = temp->right;
                    sn.push(temp);
                    ++i;
                }
                else{
                    sv.push(preorder[i]);
                    TreeNode *curr = new TreeNode(preorder[i]);
                    temp->left = curr;
                    temp = temp->left;
                    sn.push(temp);
                    ++i;
                }
            }
        }
        return root;
    }
};
