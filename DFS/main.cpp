#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,bool>visited;
    map<int,list<int>>adj;
    void addEdge(int u, int v);
    void DFS(int s);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::DFS(int s){
    visited[s]=true;
    cout<<s<<endl;
    for(list<int>::iterator i = adj[s].begin(); i!=adj[s].end(); i++){
        if(!visited[*i])
            DFS(*i);
    }
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}