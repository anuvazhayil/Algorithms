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
    if(*head == NULL){
       *head = newNode;
       return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void findVowels(Node **head){
    Node *pos = NULL, *itr = *head, *prev = NULL;
    while(itr){
        char val = itr->data;
        if(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u'){
            Node *temp = itr;
            if(!prev){
                prev = *head;
                pos = *head;
                itr = itr->next;
                continue;
            }
            //insert at the beginning
            else if(!pos){
                prev->next = itr->next;
                itr = itr->next;
                temp->next = *head;
                *head = temp;
                pos = temp;
            }
            //insert after pos(previous vowel)
            else{
                prev->next = itr->next;
                itr = itr->next;
                Node *temp2 = pos->next;
                pos->next = temp;
                temp->next = temp2;
                pos = temp;
            }
        }
        else{
            prev = itr;
            itr = itr->next;
        }
    }
}

void print(Node *head){
    while(head){
        cout<<head->data;
        head = head->next;
    }
}

int main(){
    Node *chlist = NULL;
    push(&chlist, 'a');
    push(&chlist, 'b');
    push(&chlist, 'e');
    push(&chlist, 'c');
    push(&chlist, 'd');
    push(&chlist, 'i');
    findVowels(&chlist);
    print(chlist);
    return 0;
}
