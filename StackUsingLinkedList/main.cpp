#include <bits/stdc++.h>
 
using namespace std;

class Node{
    public:
    int data;
    Node* link;
};

Node* top = NULL;

bool isEmpty(){
    return top == NULL;
}

void push(int d){
    Node* temp = new Node();
    if(!temp){
        cout<<"Heap Overflow\n";
        exit(1);
    }
    else{
        temp->data=d;
        temp->link=top;
        top=temp;
    }
}

void pop(){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        exit(1);
    }
    else{
        Node* temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

int peek() 
{ 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
}

void display() 
{ 
    struct Node* temp; 
    if (top == NULL){ 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else{ 
        temp = top; 
        while (temp != NULL){
            cout << temp->data << "-> "; 
            temp = temp->link; 
        } 
    } 
} 

int main() 
{ 
     
    // Push the elements of stack 
    push(11); 
    push(22); 
    push(33); 
    push(44); 
 
    // Display stack elements 
    display(); 
 
    // Print top element of stack 
    cout << "\nTop element is "
         << peek() << endl; 
 
    // Delete top elements of stack 
    pop(); 
    pop(); 
 
    // Display stack elements 
    display(); 
 
    // Print top element of stack 
    cout << "\nTop element is "
         << peek() << endl; 
          
    return 0; 
} 