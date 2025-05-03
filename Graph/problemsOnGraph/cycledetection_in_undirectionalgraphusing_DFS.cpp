#include<bits/stdc++.h>
using namespace std;

bool isCyclePresent(unordered_map<int, list<int>> &adjList, unordered_map<int , bool> &visited, int node, int parent){
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            if(isCyclePresent(adjList, visited, neighbour,  node)){
                return true;
            }
        }else if(neighbour != parent){
            return true;
        }
    }
    return false;
}
string isCycleFound(int n, int m, vector<vector<int>> &edges){

    unordered_map<int, list<int>> adjList;
    unordered_map<int , bool> visited;
    //creating a adjacent list
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //checking for all nodes of disconneted graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclePresent(adjList, visited, i, -1)){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
    
    int n,m;
    cout << "enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    string result = isCycleFound(n,m,edges);
    cout << "Is cycle Present: " << result << endl;

    return 0;
}