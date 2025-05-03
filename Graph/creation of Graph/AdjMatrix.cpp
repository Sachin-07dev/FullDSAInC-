#include<iostream>
#include<vector>
using namespace std;
// template < typename T>

class Graph{
     
    public:
       vector<vector<int>> adj;
       
       Graph(int nodeCount) {
        adj = vector < vector<int> > (nodeCount, vector<int> (nodeCount, 0));
       }

       void addEdges(int u, int v, bool direction){
               
            //direction -> false for undirected graph
            // direction -> true for directed graph
            adj[u][v] = 1;

            if(direction == false){
                adj[u][v] = 1;
            }
       }

       void printAdjMatrix(){
        for(int i=0; i<adj.size(); i++) {
            cout << i << " -> ";

            for(int j=0; j<adj.size(); j++) {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }
};
int main(){

    int n;
    cout <<" Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph G(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G.addEdges(u,v,false);
    }

    G.printAdjMatrix();
    
    return 0;
}