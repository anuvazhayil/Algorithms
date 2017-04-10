#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
}*start;

class linkedList{
    public:
    Node* create(int value);
    void insertbeg(int value);
    void insertlast(int value);
    void insertpos(int value, int pos);
    void deletebeg();
    void deletelast();
    void search(int value);
    void print();
};

Node* linkedList::create(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
    }
    else
        cout<<"Memory not allocated";
    return newNode;
}

void linkedList::insertbeg(int value){
    Node *newNode, *temp;
    newNode = create(value);
    if(start == NULL){
        start = newNode;
    }
    else{
        temp = start;
        start = newNode;
        start->next = temp;
    }
}

void linkedList::insertlast(int value){
    Node *newNode, *temp;
    newNode = create(value);
    if(start == NULL){
        start = newNode;
    }
    else{
        temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void linkedList::insertpos(int value, int pos){
    Node *newNode, *temp, *ptr;
    int count = 0;
    newNode = create(value);
    temp = start;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    if(pos == 1){
        if(start == NULL){
            start = newNode;
            start->next = NULL;
        }
        else{
            temp = start;
            start = newNode;
            start->next = temp;
        }
    }
    else if(pos > 1 && pos <= count){
        temp = start;
        for(int i = 1; i < pos; i++){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = newNode;
        newNode->next = temp;
    }
    else{
        cout<<"Position out of range\n";
    }
}

void linkedList::deletebeg(){
    Node *temp;
    if(!start){
        cout<<"Empty list\n";
    }
    else{
        start = start->next;
    }
}

void linkedList::deletelast(){
    Node *temp, *ptr;
    if(start){
        temp = start;
        while(temp->next != NULL){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
    }
}

void linkedList::search(int value){
    Node *temp; int flag = 0;
    if(!start){
        cout<<"List empty\n";
    }
    temp = start;
    while(temp->next != NULL){
        if(temp->data == value){
            cout<<"Found!";
            flag = 1;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    if(flag == 0)
        cout<<"Not Found!\n";
}

void linkedList::print(){
    Node* temp;
    temp = start;
    while(temp->next != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<temp->data<<"\n";
}

int main(){
    linkedList list;
    start = NULL;
    list.insertbeg(2);
    list.insertbeg(4);
    list.print();
    list.insertlast(1);
    list.insertpos(3,2);
    list.print();
    list.search(2);
    list.search(5);
    list.deletebeg();
    list.print();
    list.deletelast();
    list.print();
    return 0;
}

