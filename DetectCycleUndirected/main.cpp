#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,list<int>> adj;
    map<int, bool> visited;
    bool isCyclicUtil(int v, map<int,bool> visited, int parent);
public:
    Graph(int);
    void addEdge(int u, int v);
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int u, int v){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int s, map<int,bool> visited, int parent){
    visited[s]=true;
    for(list<int>::iterator i = adj[s].begin(); i!=adj[s].end(); i++){
        if (!visited[*i]){
           if (isCyclicUtil(*i, visited, s))
              return true;
        }
        else if(*i != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic(){
    for(int i = 0; i<adj.size(); i++)
        if(!visited[i] && isCyclicUtil(i, visited, -1))
            return true;
    return false;
}

// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
}