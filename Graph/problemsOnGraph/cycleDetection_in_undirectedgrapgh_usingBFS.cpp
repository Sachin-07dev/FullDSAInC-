#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

bool isCyclePresent(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node){
    unordered_map<int,int> parent;
    parent[node] = -1;
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while(!q.empty()){

        int frontt = q.front();
        q.pop();

        for(int neighbour : adjList[frontt]){
            if(visited[neighbour] && parent[frontt] != neighbour){
                return true;
            }

            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = frontt;
                q.push(neighbour);
            }
        }
    }
    return false;

}
string isCycleDetected(int n, int m, vector<vector<int>> &edges){
      unordered_map<int, list<int>> adjList;
      unordered_map<int, bool> visited;

      for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }

      for(int i=0;i<n;i++){
        if(visited[i] == false){
             bool res = isCyclePresent(adjList, visited, i);

             if(res){
                return "Yes";
            }
        }
      } 
      return "No";
}
int main(){

    int n,m;
    
    cout <<"Enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;
    
    vector<vector<int>> edges;
    
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    

    string sol = isCycleDetected(n,m,edges);

    cout << " Is cycle Distected: " << sol << endl;

    return 0;
}