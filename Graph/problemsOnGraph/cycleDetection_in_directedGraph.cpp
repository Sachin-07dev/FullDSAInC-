#include<bits/stdc++.h>
using namespace std;

bool isCyclePresent(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVis, int node){
    visited[node] = true;
    dfsVis[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            if(isCyclePresent(adjList, visited, dfsVis, neighbour)){
                return true;
            }
        }else if(dfsVis[neighbour]){
            return true;
        }
    }
    dfsVis[node] = false;
    return false;
}
string isCycle(vector<vector<int>> &edges, int n, int m){
     
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVis;

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v= edges[i][1];

        adjList[u].push_back(v);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclePresent(adjList, visited, dfsVis ,i)){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
    
    int n,m;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    string result = isCycle(edges, n, m);
    cout << "Is cycle present: " << result;

    return 0;
}