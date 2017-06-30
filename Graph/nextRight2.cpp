/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<pair<TreeLinkNode*, int>>q;
        pair<TreeLinkNode*, int> pNode, nNode;
        if(!root)
            return;
        if(root->left)
            q.push(make_pair(root->left, 1));
        if(root->right)
            q.push(make_pair(root->right, 1));

        while(!q.empty()){
            pNode = q.front(); q.pop();
            if(pNode.first->left)
                q.push(make_pair(pNode.first->left, pNode.second+1));
            if(pNode.first->right)
                q.push(make_pair(pNode.first->right, pNode.second+1));

            if(!q.empty() && pNode.second == q.front().second){
                nNode = q.front(); q.pop();
                pNode.first->next = nNode.first;

                if(nNode.first->left)
                    q.push(make_pair(nNode.first->left, nNode.second+1));
                if(nNode.first->right)
                    q.push(make_pair(nNode.first->right, nNode.second+1));
            }
            if(!q.empty() && q.front().second == nNode.second){
                nNode.first->next = q.front().first;
            }
        }

    }
};
