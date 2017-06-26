/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *prev = NULL, *mid = head, *last = head;

        while(last && last->next){
            prev = mid;
            mid = mid->next;
            last = last->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        if(prev)
            prev->next = NULL;
        else
            head = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};
