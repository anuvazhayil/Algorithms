#include<bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    Node* next;
};

Node* insert(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, char data){
    Node *newNode = insert(data);
    newNode->next = (*head);
    (*head) = newNode;
}

int compare(Node* stringone, Node* stringtwo){
    while(stringone && stringtwo && (stringone->data == stringtwo->data)){
        stringone = stringone->next;
        stringtwo = stringtwo->next;
    }

    if(stringone && !stringtwo){
        return 1;
    }
    if(stringtwo && !stringone){
        return -1;
    }
    if (stringone && stringtwo){ 
        if(stringone->data > stringtwo->data){
            return 1;   
        }
        else 
            return -1;
    }

    return 0;
}

int main(){
    Node *first = NULL, *second = NULL;
    int res;
    push(&first, 'a');
    push(&first, 'd');
    push(&first, 'g');
    push(&first, 'b');
        
    push(&second, 'a');
    push(&second, 'd');
    push(&second, 'g');
    push(&second, 'b');
    //push(&second, 'b');
        
    res = compare(first, second);
    cout<<res;

    return 0;
}
