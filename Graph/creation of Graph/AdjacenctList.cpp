#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    
    public: 
       unordered_map<T, vector<T>> adj;

    void addEdges(T u, T v, bool direction){

        //adj[u].push_back(v);

        if(direction == false){
            adj[u].push_back(v);
        }
    } 
    
    void printAdjList(){
        for(auto i : adj) {
            cout << i.first << " -> ";

            for(auto j : i.second) {
                cout << j << " ";
            }

            cout << endl;
        }
    }
    
};

int main(){
    
    int n;
    cout << " Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph<int> G;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G.addEdges(u,v,false);
    }
    G.printAdjList();

    return 0;
}