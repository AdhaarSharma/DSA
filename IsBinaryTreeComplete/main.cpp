#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to check if a given binary tree is a complete tree or not
bool isComplete(Node* root, int i, int n)
{
    // return if the tree is empty
    if (root == nullptr) {
        return true;
    }
 
    if ((root->left && 2*i + 1 >= n) || !isComplete(root->left, 2*i + 1, n)) {
        return false;
    }
 
    if ((root->right && 2*i + 2 >= n) || !isComplete(root->right, 2*i + 2, n)) {
        return false;
    }
 
    return true;
}
 
// Utility function to calculate the total number of nodes in a binary tree
int size(Node* root)
{
    // base case
    if (root == nullptr) {
        return 0;
    }
 
    return 1 + size(root->left) + size(root->right);
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    if (isComplete(root, 0, size(root))) {
        cout << "The given binary tree is a complete binary tree";
    }
    else {
        cout << "The given binary tree is not a complete binary tree";
    }
 
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Utility function to calculate the total number of nodes in a binary tree
int size(Node* root)
{
    // base case
    if (root == nullptr) {
        return 0;
    }
 
    return 1 + size(root->left) + size(root->right);
}
 
// Perform inorder traversal on the binary tree and fill array `A[]`
void inorder(Node* root, vector<bool> &A, int i)
{
    if (root == nullptr) {
        return;
    }
 
    // recur with index `2i+1` for left node
    inorder(root->left, A, 2*i + 1);
 
    // mark index `i` as visited
    A[i] = true;
 
    // recur with index `2i+2` for the right node
    inorder(root->right, A, 2*i + 2);
}
 
// Function to check if a given binary tree is a complete binary tree or not
bool isComplete(Node* root, int n)
{
    // return if the tree is empty
    if (root == nullptr) {
        return true;
    }
 
    // construct an auxiliary boolean array of size `n`
    vector<bool> A(n, false);
 
    // fill array `A[]`
    inorder(root, A, 0);
 
    // check if all positions in the array are filled or not
    for (int i = 0; i < n; i++)
    {
        if (!A[i]) {
            return false;
        }
    }
 
    return true;
}
 
int main()
{
    /* Construct the following tree
             1
           /   \
          /     \
         2       3
        / \     / \
       4   5   6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    if (isComplete(root, size(root))) {
        cout << "The given binary tree is a complete binary tree";
    }
    else {
        cout << "The given binary tree is not a complete binary tree";
    }
 
    return 0;
}


#include <iostream>
#include <list>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Function to check if a given binary tree is complete or not
bool isComplete(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return false;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    // pointer to store the current node
    Node* front = nullptr;
 
    // flag to mark the end of full nodes
    bool flag = false;
 
    // loop till queue is empty
    while (queue.size())
    {
        // dequeue front node
        front = queue.front();
        queue.pop_front();
 
        // if we have encountered a non-full node before and the current node
        // is not a leaf, a tree cannot be complete
        if (flag && (front->left || front->right)) {
            return false;
        }
 
        // if the left child is empty and the right child exists,
        // a tree cannot be complete
        if (front->left == nullptr && front->right) {
            return false;
        }
 
        // if the left child exists, enqueue it
        if (front->left) {
            queue.push_back(front->left);
        }
        // if the current node is a non-full node, set the flag to true
        else {
            flag = true;
        }
 
 
        // if the right child exists, enqueue it
        if (front->right) {
            queue.push_back(front->right);
        }
        // if the current node is a non-full node, set the flag to true
        else {
            flag = true;
        }
    }
 
    return true;
}
 
int main()
{
    /* Construct the following tree
              1
           /    \
          2      3
         / \    / \
        4   5  6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    if (isComplete(root)) {
        cout << "The given binary tree is a complete binary tree";
    }
    else {
        cout << "The given binary tree is not a complete binary tree";
    }
 
    return 0;
}