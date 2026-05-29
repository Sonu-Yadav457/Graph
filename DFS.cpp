#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l; //We use dynamic array of list because we don't know the number of vertices in advance

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; //Creating a dynamic array of list of size V
    }
    void addEdge(int u, int v){
        l[u].push_back(v); //Add v to u's list
        l[v].push_back(u); //Add u to v's list because the graph is undirected
    }
    
    void dfsHelper(int src, vector<bool> &visited){
        visited[src] = true;
        cout <<src << " ";
        for(int v : l[src]){
            if(!visited[v]){
                dfsHelper(v, visited);
            }
        }
    }
    
    void dfs(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsHelper(i, visited);
            }
        }
    }
};

int main(){
    Graph g(5); //Creating a graph with 5 vertices
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.dfs();

    

    return 0;
}