#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int value){

    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Constructs BST from a sorted array */
TreeNode* constructBST(vector<int>& nums, int start, int end){

    if(start > end)
        return NULL;

    int mid = (start + end)/2;
    TreeNode *root = newNode(nums[mid]);
    root->left = constructBST(nums, start, mid-1);
    root->right = constructBST(nums, mid+1, end);

    return root;
}

void printPreorder(TreeNode *root){
    if(!root){
        return;
    }
    cout<<root->val;
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){

    int len, ele;
    cin>>len;
    vector<int>nums;
    for(int i = 0; i < len; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    TreeNode* root = constructBST(nums, 0, len-1);
    printPreorder(root);
    return 0;
}
