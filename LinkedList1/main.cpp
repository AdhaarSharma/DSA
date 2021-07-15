#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};
a
void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)->next = new_node;
}

void insertAfter(Node* prev_node, int new_data){
    if(prev_node==NULL){
        cout<<"The given previous node cannot be null"<<endl;
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data){
    Node* new_node = new Node();
    Node* last = (*head_ref);
    new_node->data = new_data;
    new_node->next = NULL;
    if(head_ref == NULL){
        (*head_ref) = new_node;
        return;
    }
    while(last != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(Node* node){
    while(node!=NULL){
        cout<<" "<<node->data;
        node=node->next;
    }
}

int main(){
    
    Node* head;
    Node* second;
    Node* third;
    
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->next = second;
    head->data = 1;
    second->next = third;
    second->data = 2;
    third->next = NULL;
    third->data = 3;
    printList(head);
}