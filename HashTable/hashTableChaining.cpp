#include<bits/stdc++.h>

using namespace std;

class Hashnode{
    int data;
    Node* next;
    public:
    Node* insert(char data);
    void push(Node** head, char data);
};

Node* Node::insert(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Node::push(Node** head, char data){
    Node *newNode = insert(data);
    newNode->next = (*head);
    (*head) = newNode;
}

class hashTable{
    Hashnode ** ht;

    public:
    int hash(string key);
    void insert();
    void print(hashTable ht);
};

int hashTable::hash(string key){
    int sum = 0;
    for(int i = 0; i < key.size(); i++){
        sum += key[i];
    }
}

void hashTable::insert(){

}

void hashTable::print(){

}

int main(){

    return 0;
}
