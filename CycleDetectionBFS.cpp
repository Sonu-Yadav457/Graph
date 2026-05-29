#include<iostream>
#include<list>
#include<queue>
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
    
    bool isCycleHelper(int src, vector<bool> &visited){
        queue<pair<int, int>> q; // pair of vertex and its parent
        

        visited[src] = true;
        q.push({src, -1});

        while(q.size() > 0){
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int v : l[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v, u});
                }
                else if( v != parent){
                    return true; // Cycle detected
                }
            }
        }
        return false; // No cycle detected
    }
    void isCycle(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(isCycleHelper(i, visited)){
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