#include<bits/stdc++.h>
using namespace std;

void traversal(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
     queue<int> q;
     q.push(node);
     visited[node] = 1;

     while(!q.empty()){
        int front = q.front();
        q.pop();

        visited[front] = 1;
        ans.push_back(front);

        for(auto i : adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
     }
}
vector<int> BFS(vector<pair<int,int>> &edges, int vertex){

    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    //creating a adjacency list;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for(int i=0;i<vertex;i++){
       if(!visited[i]){
          traversal(adjList, visited,ans ,i);
        }
   }
   return ans;
}
int main(){
    
    int n,m;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int,int>> edges(m,{0,0});

    for(int i=0;i<m;i++){
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    vector<int> res = BFS(edges, n);

    cout << "BFS Traversal: ";
    for(auto i: res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}