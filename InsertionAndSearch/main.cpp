#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

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


int main()
{
	// Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0; 
}