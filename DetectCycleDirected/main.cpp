#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int,list<int>> adj;
    map<int,bool> recStack;
    map<int,bool> visited;
    bool isCyclicUtil(int s);
public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int s){
    if(visited[s]==false){
        recStack[s] = true;
        visited[s] = true;
        for(list<int>::iterator i = adj[s].begin(); i!=adj[s].end(); i++){
            if(!visited[*i] && isCyclicUtil(*i))
                return true;
            else if(recStack[*i])
                return true;
        }
    }
    recStack[s]=false;
    return false;
}

bool Graph::isCyclic(){
    for(int i = 0; i<adj.size(); i++)
        if(isCyclicUtil(i))
            return true;
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}