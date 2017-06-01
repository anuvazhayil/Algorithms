#include<bits/stdc++.h>
    
using namespace std;

struct Node{
    int data;
    Node *next;
};

void insertBeg(Node **head, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node **head, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
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

void insertPos(Node **head, int pos, int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    Node *temp = *head;
    while(pos-2){
        temp = temp->next;
        --pos;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeg(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    delete(temp);
}

void deleteEnd(Node **head){
    Node *temp = *head;
    Node *prev;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete(temp);
}

void deletePos(Node **head, int pos){
    Node *temp = *head;
    while(pos-2){
        temp = temp->next;
        pos--;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete(temp2);
}

int search(Node *head, int val){
    int pos = 1;
    while(head != NULL){
        if(head->data == val)
            return pos;
        else{
            head = head->next;
            ++pos;
        }
    }
    return 0;
}

void reverseRec(Node *p, Node **head){
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverseRec(p->next, head);
    p->next->next = p;
    p->next = NULL;
}

void reverseItr(Node **head){
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = (*head)->next;
    while(next != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    *head = curr;
}

void print(Node *head){
    cout<<"\n";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void printRev(Node *head){
    if(head == NULL)
        return;
    printRev(head->next);
    cout<<head->data<<" ";
}

int firstEle(Node *head){
    return head->data;    
}

int lastEle(Node *head){
    cout<<"\n";
    Node* prev = head;
    while(prev->next != NULL){
        prev = prev->next;
    }
    return prev->data;
}

int count(Node *head){
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

int main(){
    Node* head = NULL;
    
    insertBeg(&head, 4);
    print(head);
    insertBeg(&head, 2);
    print(head);
    insertBeg(&head, 1);
    print(head);
    insertEnd(&head, 22);
    print(head);
    insertEnd(&head, 33);
    print(head);
    insertPos(&head, 4, 15);
    print(head);
    insertPos(&head, 4, 10);
    print(head);
    cout<<"\nFirst element: "<<firstEle(head);
    cout<<"\nLast element: "<<lastEle(head);
    deleteBeg(&head);
    print(head);
    deleteEnd(&head);
    print(head);
    deletePos(&head, 4);
    print(head);
    cout<<"\nNumber of elements: "<<count(head);
    reverseItr(&head);
    print(head);
    reverseRec(head, &head);
    print(head);
    printRev(head);
    int pos = search(head, 10);
    if(pos){
        cout<<"\nElement found at: "<<pos;
    }
    else{
        cout<<"\nElement not found!";
    }

    return 0;
}
