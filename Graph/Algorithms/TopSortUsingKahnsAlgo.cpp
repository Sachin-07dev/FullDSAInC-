#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, list<int>> &adjList,vector<bool> &visited, vector<int> &indegree, vector<int> &ans, queue<int> &q){

   if(q.empty()){
       return;
   }

   int front = q.front();
   q.pop();
   ans.push_back(front);//importnt part of the function
   visited[front] = true;

   for(auto neighbour : adjList[front]){
       indegree[neighbour]--;

       if(!visited[neighbour] && indegree[neighbour] == 0){
        q.push(neighbour);
       }
   }

   bfs(adjList, visited, indegree,ans,q);
}
vector<int> KahnsAlgo(vector<vector<int>> &edges, int n, int m){

    unordered_map<int, list<int>> adjList;
    queue<int> q;
    vector<bool> visited(n,0);
    vector<int> indegree(n,0);

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        indegree[v]++;
    }
    
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(adjList, visited, indegree, ans, q);
        }
    }
    return ans;
}
int main(){

    int n,m;
    cout <<" Enter the n & m: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = KahnsAlgo(edges, n,m);

    for(auto val : topSort){
        cout << val << " ";
    }

    return 0;
}