#include <bits/stdc++.h>>
using namespace std;

#define MAX 26

struct trieNode{
    bool isEnd=false;
    struct trieNode* child[MAX];
};

struct trieNode* trieNewNode(){
    struct trieNode* newNode = new trieNode();
    for(int i=0; i<MAX; i++){
        newNode->child[i]=NULL;
    }
    return newNode;
};

void insert(struct trieNode* root, string str){
    int len = str.length();
    trieNode *pCrawl = root;
    for(int i=0; i<len; i++){
        int index = str[i] - 'a';
        if(!pCrawl->child[index]){
            pCrawl->child[index] = trieNewNode();
        }
        pCrawl=pCrawl->child[index];
    }
    pCrawl->isEnd=true;
}

bool search(struct trieNode* root, string str){
    trieNode *pCrawl = root;
    for(int i=0; i<str.length(); i++){
        int index = str[i] - 'a';
        if(!pCrawl->child[index]){
            return false;
        }
        pCrawl=pCrawl->child[index];        
    }
    return((pCrawl->isEnd)&&(pCrawl!=NULL));
}

bool wordBreak(string str, trieNode* root){
    int size = str.length();
    //Base Case
    if(size==0){
        return true;
    }
    for(int i=1; i<=size; i++){
        if((search(root, str.substr(0,i)))&&(wordBreak(str.substr(i,size-1),root)))
            return true;
    }
    return false;
}

// Driver program to test above functions 
int main() 
{ 
    string dictionary[] = {"mobile","samsung","sam", 
                           "sung","ma\n","mango", 
                           "icecream","and","go","i", 
                           "like","ice","cream"}; 
    int n = sizeof(dictionary)/sizeof(dictionary[0]); 
    struct trieNode *root = trieNewNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, dictionary[i]); 
  
    wordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("", root)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n"; 
    return 0; 
} 
