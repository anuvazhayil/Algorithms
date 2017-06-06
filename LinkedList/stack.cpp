#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data){
    Node* newNode = insert(data);
    newNode->next = (*head);
    (*head) = newNode;  
}

void pop(Node** head){
    (*head) = (*head)->next;
}

void print(Node* stack){
    while(stack){
        cout<<stack->data;
        stack = stack->next;
    }
    cout<<"\n";
}

int main(){
    Node* stack = NULL;
    push(&stack,2);
    push(&stack,3);
    push(&stack,5);
    push(&stack,10);
    print(stack);
    pop(&stack);
    print(stack);
    return 0;
}
