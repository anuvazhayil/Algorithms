#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data){
    Node *newNode = insert(data);
    newNode->next = (*head);
    (*head) = newNode;
}

Node* sum(Node* first, Node* second){
    Node* res = NULL;
    Node *temp = NULL, *prev = NULL;
    int sum, carry = 0;
    while(first != NULL || second != NULL){
        sum = carry + (first? first->data:0) + (second? second->data:0);
        if(sum >= 10){
            carry = 1;
            sum %= 10;
        }
        else
            carry = 0;
        
        temp = insert(sum);

        if(res == NULL){
            res = temp;
        }
        else{
            prev->next = temp;
        }
        
        prev = temp;

        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }
    
    if(carry > 0){
        temp->next = insert(carry);
    }
    return res;
}

void print(Node* list){
    while(list){
        cout<<list->data;
        list = list->next;
    }
    cout<<"\n";
}

int main(){
    Node *first = NULL, *second = NULL, *res = NULL;
    
    push(&first, 3);
    push(&first, 8);
    push(&first, 9);
    push(&first, 2);
    print(first);

    push(&second, 1);
    push(&second, 4);
    push(&second, 6);
    push(&second, 3);
    push(&second, 2);
    print(second);

    res = sum(first, second);
    print(res);

    return 0;
}

