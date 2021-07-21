#include<bits/stdc++.h> 
using namespace std; 

#define MAX 256
#define MAX_WORD_LEN  500

struct trieNode{
    trieNode* child[MAX];
    int freq;
};

struct trieNode* newTrieNode(){
    trieNode* newNode = new trieNode();
    newNode->freq = 1;
    for(int i=0; i<MAX; i++){
        newNode->child[i]=NULL;
    }
    //don't forget the return statement
    return newNode;
}

void insert(trieNode *root, string str){
    int len = str.length();
    //to traverse we create pCrawl
    struct trieNode *pCrawl = root;
    for(int i=0; i<len; i++){
        int index = str[i];
        if(!pCrawl->child[index])
            pCrawl->child[index] = newTrieNode();
        else{
            (pCrawl->child[index]->freq)++;
        }
        pCrawl = pCrawl->child[index];
    }
}

void findPrefixUtil(trieNode *root, char prefix[], int idx){
    if(root==NULL)
        return;
    if(root->freq==1){
        prefix[idx]='\0';
        cout<<prefix<<" ";
        return;
    }
    for(int i=0; i<MAX; i++){
        if(root->child[i]!=NULL){
            prefix[idx]=i;
            findPrefixUtil(root->child[i], prefix, idx+1);
        }
    }
}

void findPrefix(string arr[], int n){
    struct trieNode *root = newTrieNode();
    root->freq=0;
    for(int i=0; i<n; i++){
        insert(root,arr[i]);
    }
    char prefix[MAX_WORD_LEN];
    findPrefixUtil(root, prefix, 0);
}

int main() 
{ 
    string arr[] = {"zebra", "dog", "duck", "dove"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findPrefix(arr, n); 
  
    return 0; 
} 