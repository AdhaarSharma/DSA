#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int FindHeight(Node* root){
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main(){
	printf("hello world\n");
	return 0;
}
