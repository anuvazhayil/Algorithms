#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* create(int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

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

void reverseRec(Node *p, Node **head){
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverseRec(p->next, head);
    p->next->next = p;
    p->next = NULL;
}

void multiplyRow(Node *num1, Node *num2, Node*res){
    int mult, carry = 0;
    while(num2){
        mult = num1->data * num2->data + carry + res->data;
        int val = mult % 10;
        carry = mult / 10;
        res->data = val;
        num1 = num1->next;
        if(!res->next){
            res->next = create(0);
        }
        res = res->next;
    }
    if(carry){
        res->data += carry;
    }
}

Node* multiply(Node *head1, Node *head2){
    if(!head1 || !head2){
        return NULL;
    }

    Node* res = create(0);
    Node* temp = res;
    //each row of multiplied part
    while(head1){
        multiplyRow(head1, head2, temp);
        head1 = head1->next;
        temp = temp->next;
    }

    reverseRec(res, &res);
    if(res->data == 0 && res->next){
        Node* temp = res;
        res = res->next;
        delete(temp);
    }

    return res;
}

void print(Node *head){
    cout<<"\n";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main(){
    Node* num1 = NULL;
    Node* num2 = NULL;
    insertBeg(&num1,1);
    insertBeg(&num1,2);
    insertBeg(&num1,3);
    insertBeg(&num2,4);
    insertBeg(&num2,5);
    insertBeg(&num2,6);

    //123 * 456
    Node *res = multiply(num1, num2);
    print(res);
    return 0;
}
