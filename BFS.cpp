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
    
    void bfsHelper(int src, vector<bool> &visited){
        queue<int> q;
        

        visited[src] = true;
        q.push(src);

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout << u << " ";

            for(int v : l[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    void bfs(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bfsHelper(i, visited);
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

    g.bfs();

    

    return 0;
}