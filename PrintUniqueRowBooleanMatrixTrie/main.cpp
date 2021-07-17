// Given a binary matrix of M X N of integers, 
// you need to return only unique rows of binary array 
#include <bits/stdc++.h>
using namespace std;
#define ROW 4 
#define COL 5 
  
// A Trie node 
class Node 
{ 
    public:
    bool isEndOfCol; 
    Node *child[2]; // Only two children needed for 0 and 1 
} ; 
  
  
// A utility function to allocate memory
// for a new Trie node 
Node* newNode() 
{ 
    Node* temp = new Node(); 
    temp->isEndOfCol = 0; 
    temp->child[0] = temp->child[1] = NULL; 
    return temp; 
}

bool insert(Node** root, int (*M)[COL], int row, int col){
    if(*root==NULL)
        *root = newNode();
    if(col<COL){
        return insert(&((*root)->child[M[row][col]]), M, row, col+1);
    }
    else{
        if(!((*root)->isEndOfCol))
            return (*root)->isEndOfCol=1;
        return 0;
    }
}

// A utility function to print a row 
void printRow(int(*M)[COL], int row) 
{ 
    int i; 
    for(i = 0; i < COL; ++i) 
        cout << M[row][i] << " "; 
    cout << endl;
}

void findUniqueRows(int (*M)[COL]){
    Node* root=NULL;
    for(int i=0; i<ROW; i++){
        if(insert(&root,M,i,0))
            printRow(M, i);
    }
}

// Driver Code
int main() 
{ 
    int M[ROW][COL] = {{0, 1, 0, 0, 1}, 
                       {1, 0, 1, 1, 0}, 
                       {0, 1, 0, 0, 1}, 
                       {1, 0, 1, 0, 0}}; 
  
    findUniqueRows(M); 
  
    return 0; 
}