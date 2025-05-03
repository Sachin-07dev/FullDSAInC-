#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,vector<int> &component, int node ){

   component.push_back(node);
   visited[node] = 1;

   for(auto i : adjList[node]){
       if(!visited[i]){
           bfs(adjList, visited,component, i);
           
       }
   }
}
vector<vector<int>> DFS(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> answer;
    unordered_map<int, bool> visited;

    for(int i=0;i<edges.size();i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        vector<int> component;
        bfs(adjList, visited, component, i);
        answer.push_back(component);
    }

    return answer;
}
int main(){
    
    int n,m;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m,{0,0});

    for(int i=0;i<m;i++){
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector<vector<int>> sol = DFS(edges, n, m);

    for(auto i : sol){
        for(auto j : i){
            cout << j << " ";
        }
    }cout << endl;

    return 0;
}