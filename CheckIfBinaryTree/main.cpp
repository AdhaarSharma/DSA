#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

bool isSmallerSubtree(Node* root, int value){
    if(root == NULL)
        return true;
    if(root->data < value && isSmallerSubtree(root->left, value) && isSmallerSubtree(root->right, value))
        return true;
    else
        return false;
}

bool isGreaterSubtree(Node* root, int value){
    if(root == NULL)
        return true;
    if(root->data > value && isGreaterSubtree(root->left, value) && isGreaterSubtree(root->right, value))
        return true;
    else
        return false;
}

bool isBinarySearchTree(Node* root){
    if(root == NULL)
        return true;
    if(isSmallerSubtree(root->left, root->data) && isGreaterSubtree(root->right, root->data) &&
    isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
        return true;
    else
        return false;
}

int main(){
	return 0;
}
