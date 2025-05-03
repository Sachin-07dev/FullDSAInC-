#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, int src, int dest, vector<vector<int>> &edges){

    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adjList[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    vector<int> path;
    int temp = dest;
    path.push_back(temp);
    while(temp != src){
        path.push_back(temp);
        temp = parent[temp];
    }
       path.push_back(src);

    reverse(path.begin(), path.end());
    return path;
}
int main(){

    int n,m;
    cout << "Enter the n & m: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
       int u,v;
       cin >> u >> v;
       edges.push_back({u,v});
    }

    int src, dest;
    cout << "Enter the value of src and destination: ";
    cin >> src >> dest;

    vector<int> sPath = shortestPath(n,m,src,dest,edges);
    cout << "Shortest Path is: ";
    
    for(int i=0;i<sPath.size();i++){
        cout << sPath[i] ;
        if(i != sPath.size()-1) cout << "->";
    }

    return 0;
}