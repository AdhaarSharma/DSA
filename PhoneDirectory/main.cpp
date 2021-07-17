#include <bits/stdc++.h>
#include <map>
using namespace std;

struct Trie{
    map<char,Trie*>child;
    bool isEnd;
    Trie(){
        for(char i = 'a'; i<='z'; i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
};

struct Trie* root = NULL;

void insert(string str){
    Trie* pcrawl = root;
    for(int i=0; i<str.length(); i++){
        Trie* nextNode = pcrawl->child[str[i]];
        if(nextNode == NULL){
            nextNode = new Trie();
            pcrawl->child[str[i]] = nextNode;
        }
        pcrawl = nextNode;
        if(i == str.length() - 1)
            pcrawl->isEnd = true;
    }
}

void displayContactUtil(string prefix, Trie* curNode){
    if(curNode->isEnd)
        cout<<prefix<<endl;
    for(int i='a'; i<='z'; i++){
        struct Trie* nextNode = curNode->child[i];
        if(nextNode!=NULL)
            displayContactUtil(prefix+(char)i, nextNode);
    }
}

void displayContacts(string str){
    int len = str.length();
    struct Trie* prevNode = root;
    string prefix = "";
    int i;
    for(i=0; i<len; i++){
        prefix += str[i];
        char lastchar = str[i];
        struct Trie* curNode = prevNode->child[lastchar];
        if(curNode==NULL){
            cout<<"No Result found for prefix: "<<prefix<<endl;
            i++;
            break;
        }
        cout<<"Suggestions based on prefix: "<<prefix<<endl;
        displayContactUtil(prefix, curNode);
        prevNode = curNode;
    }
    for(; i<len; i++){
        prefix += str[i];
        cout<<"No Result found for prefix: "<<prefix<<endl;
    }
}

void insertIntoTrie(string contacts[], int n){
    root = new Trie();
    for(int i=0; i<n; i++){
        insert(contacts[i]);
    }
}

// Driver program to test above functions
int main()
{
    // Contact list of the User
    string contacts[] = {"gforgeeks" , "geeksquiz"};
  
    // Size of the Contact List
    int n = sizeof(contacts)/sizeof(string);
  
    // Insert all the Contacts into Trie
    insertIntoTrie(contacts, n);
  
    string query = "gekk";
  
    // Note that the user will enter 'g' then 'e', so
    // first display all the strings with prefix as 'g'
    // and then all the strings with prefix as 'ge'
    displayContacts(query);
  
    return 0;
}