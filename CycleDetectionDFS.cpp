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
    //Concept is simple we need to check whether the back edge is present or not. If the back edge is present then we can say that there is a cycle in the graph. Back edge is an edge which is already visited and it is not the parent of the current node.
    //So need to track Visited and parent.
    bool isCycleHelper(int src, vector<bool> &visited, int parent){
        visited[src] = true;
        
        for(int v : l[src]){
            if(!visited[v]){
                if(isCycleHelper(v, visited, src)){
                    return true;
                }
                else if( v != parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    void isCycle(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(isCycleHelper(i, visited, -1)){
                    cout << "Cycle detected" << endl;
                    return;
                }
            }
        }
        cout << "No cycle detected" << endl;
    }
};

int main(){
    Graph g(5); //Creating a graph with 5 vertices
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.isCycle();

    return 0;
}