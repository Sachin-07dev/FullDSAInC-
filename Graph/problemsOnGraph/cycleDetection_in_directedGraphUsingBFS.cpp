#include<bits/stdc++.h>
using namespace std;

bool isCycle(int n, int m, vector<pair<int,int>> &edges){
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(n,0);
    queue<int> q;

    for(int i=0;i<n;i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        indegree[i]++;
    }

    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    int cnt = 0;
    while(!q.empty()){
         
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbour : adjList[front]){
            indegree[neighbour]--;

            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return (cnt == n) ? false : true;
}
int main(){

    int n,m;
    cout << "Enter n&m: ";
    cin >> n >> m;

    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    if(isCycle(n,m,edges)){
        cout << "Cycle is Present. ";
    }else{
        cout << "Cycle is not present. ";
    }
    return 0;
}