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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(!inorder.size())
            return NULL;

        stack<int>sv;
        stack<TreeNode*>sn;
        int len = inorder.size();
        int i = len-1, j = len-2, ins_left = 0;

        TreeNode *root = new TreeNode(postorder[len-1]);
        TreeNode *temp = root;
        sv.push(postorder[len-1]);
        sn.push(temp);

        while(j >= 0){
            if(!sv.empty() && sv.top() == inorder[i]){
                ins_left = 1;
                sv.pop();
                temp = sn.top();
                sn.pop();
                --i;
            }
            else{
                if(ins_left){
                    ins_left = 0;
                    sv.push(postorder[j]);
                    temp->left = new TreeNode(postorder[j]);
                    temp = temp->left;
                    sn.push(temp);
                    --j;
                }
                else{
                    sv.push(postorder[j]);
                    temp->right = new TreeNode(postorder[j]);
                    temp = temp->right;
                    sn.push(temp);
                    --j;
                }
            }
        }

        return root;
    }
};
