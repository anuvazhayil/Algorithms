#include<bits/stdc++.h>

using namespace std;

struct treeNode{
    int data;
    treeNode *left, *right;
};

treeNode* create(int val){
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

treeNode* insert(treeNode *root, int val){
    if(root == NULL){
        root = create(val);
    }
    else if(val <= root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(treeNode* root, int val){
    if(val == root->data)
        return true;
    else if(val < root->data){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
    return false;
}

treeNode* rightMin(treeNode *node){
    while(node->left){
        node = node->left;
    }
    return node;
}

treeNode* deleteNode(treeNode* root, int val){
    if(root == NULL){
        return root;
    }
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    //found
    else{
        //no child nodes
        if(!root->right && !root->left){
            delete root;
            root = NULL;
            return root;
        }
        //one child node
        else if(!root->right || !root->left){
            treeNode *temp;
            (root->right)? temp = root->right : temp = root->left;
            delete root;
            return temp;
        }
        //two child nodes
        else{
            treeNode *temp = rightMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            return root;
        }
    }
}

void printInorder(treeNode *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(treeNode *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(treeNode *root){
    if(root == NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

void printPreorderItr(treeNode *root){
    stack<treeNode*>nodes;
    while(root || !nodes.empty()){
        if(root){
            cout<<root->data;
            nodes.push(root);
            root = root->left;
        }
        else{
            root = nodes.top()->right;
            nodes.pop();
        }
    }
}

void printInorderItr(treeNode *root){
    stack<treeNode*>nodes;
    while(root || !nodes.empty()){
        if(root){
            nodes.push(root);
            root = root->left;
        }
        else{
            cout<<nodes.top()->data;
            root = nodes.top()->right;
            nodes.pop();
        }
    }
}

void printPostorderItr(treeNode *root){
    stack<treeNode*>nodes;
    treeNode *prev = NULL;
    nodes.push(root);
    while(!nodes.empty()){
        root = nodes.top();
        //parsing down
        if(prev == NULL || root == prev->left || root == prev->right){
            if(root->left)
                nodes.push(root->left);
            else if(root->right)
                nodes.push(root->right);
            else if(!root->left && !root->right){
                cout<<root->data<<" ";
                nodes.pop();
            }
        }
        //parsing up from left
        else if(prev == root->left){
            if(root->right){
                nodes.push(root->right);
            }
            else{
                cout<<root->data<<" ";
                nodes.pop();
            }
        }
        else if(prev == root->right){
            cout<<root->data<<" ";
            nodes.pop();
        }
        prev = root;
    }
}

int lowestCommonAncestor(treeNode *root, int p, int q) {
    treeNode* ancestor = root;
    while(root){
        if(root->data > p && root->data > q){
            ancestor = root->left;
            root = root->left;
        }
        else if(root->data < p && root->data < q){
            ancestor = root->right;
            root = root->right;
        }
        else{
            ancestor = root;
            return ancestor->data;
        }
    }
    return ancestor->data;
}

/*treeNode* treeNode::inorderPredecessor(treeNode* node){
    if(node == NULL)
        return NULL;
    else{
        if(node->getleftChild() != NULL){
            treeNode* temp = node->getleftChild();
            while(temp->getrightChild() != NULL){
               temp = temp->getrightChild();
            }
            return temp;
        }
        else{

        }
    }
}

treeNode* treeNode::inorderSuccessor(treeNode* node){
    if(node == NULL)
        return NULL;
    else{
        if(node->getrightChild() != NULL){
            treeNode* temp = node->getrightChild();
            while(temp->getleftChild() != NULL){
                temp = temp->getleftChild();
            }
            return temp;
        }
        else{

        }
    }
}*/

int main(){
    treeNode *root = NULL;
    root = insert(root, 7);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 5);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 10);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 2);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 6);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 8);
    printPostorderItr(root);
    cout<<"\n";
    root = insert(root, 12);
    printPostorderItr(root);
    cout<<"\n";
    root = deleteNode(root, 7);
    printPostorderItr(root);
    cout<<"\n";
    cout<<lowestCommonAncestor(root, 10, 12);
    return 0;
}
