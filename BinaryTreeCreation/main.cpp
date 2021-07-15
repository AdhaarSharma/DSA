#include <iostream>
using namespace std;

struct Node{
        int data;
        Node* left;
        Node* right;
};

Node* Create(){
    int x;
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if(x==-1)
        return 0;
    newNode->data = x;
    printf("Enter left child of %d", x);
    newNode->left = Create();
    printf("Enter right child of %d", x);
    newNode->right = Create();
    return newNode;
}

int main(){
    Node* root = NULL;
    root = Create();
	return 0;
}