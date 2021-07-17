#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

bool isBstUtil(Node* root, int minValue, int maxValue){
    if(root == NULL)
        return true;
    if(root->data >= minValue && root->data <= maxValue &&
    isBstUtil(root->left, minValue, root->data) && isBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool isBinarySearchTree(Node* root){
    return isBstUtil(root, INT_MIN, INT_MAX);
}

int main(){
    return 0;
}
