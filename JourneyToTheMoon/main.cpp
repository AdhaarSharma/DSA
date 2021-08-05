#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

map<int,list<int>> adj;
map<int,bool> visited;
int counter;

void DFS(int u)
{
    visited[u] = true;
    counter++;
    
    list<int>::iterator it;
    
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(!visited[*it])
        {
            DFS(*it);
        }
    }
}

int main()
{
    int numComponents = 0;
    int V, E;
    cin >> V >> E;
    vector<int> eachC;
    int u, v;
    for(int i=0;i<E;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    for(int i=0; i<V; i++){
        if(!visited[i])
            DFS(i);
        eachC.push_back(counter);
        numComponents++;
    }
    long long int totalWays = V*(V-1) / 2;
    long long int sameWays = 0;
    
    for(int i=0;i<numComponents;i++)
    {    
        sameWays = sameWays + (eachC[i]*(eachC[i]-1) / 2);
    }
    cout << (totalWays - sameWays) << endl;

    return 0;
}