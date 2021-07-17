#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0]) 

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* getNode(void){
    TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
        
        //Can also use memset(children, 0, sizeof(children));
    for(int i = 0; i<ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode* root, string key){
    struct TrieNode* pCrawl = root;
    for(int i=0; i<key.length(); i++){
        int idx = key[i] - 'a';
        if(!pCrawl->children[idx]){ //or if(pCrawl->children[idx]==NULL){
            pCrawl->children[idx] = getNode();
        }
        pCrawl = pCrawl->children[idx];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key){
    struct TrieNode* pCrawl = root;
    for(int i=0; i<key.length(); i++){
        int idx = key[i] - 'a';
        if(!pCrawl->children[idx]){
            return false;
        }
        pCrawl = pCrawl->children[idx];
    }
    return (pCrawl!=NULL && pCrawl->isEndOfWord);
}

void display(TrieNode* root, char str[], int level){
    if(root->isEndOfWord){
        str[level] = '\0';
        cout<<str<<endl;
    }
    for(int i=0; i<ALPHABET_SIZE;i++){
        if(root->children[i]){
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

int main()
{
	// Keys to be inserted in Trie 
    char keys[][8] = { "the", "a", "there", "answer", 
                       "any", "by", "bye", "their" }; 
  
    struct TrieNode* root = getNode(); 
  
    // Inserting keys in Trie 
    for (int j = 0; j < ARRAY_SIZE(keys); j++) 
        insert(root, keys[j]); 
  
    int level = 0; 
    char str[20]; 
  
    // Displaying content of Trie 
    cout << "Content of Trie: " << endl; 
    display(root, str, level); 
}