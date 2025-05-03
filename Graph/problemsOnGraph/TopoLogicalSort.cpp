#include<bits/stdc++.h>
using namespace std;

void topSort(unordered_map<int, list<int>> &adjList, vector<bool> &visited, stack<int> &st, int node){
      
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            topSort(adjList, visited, st, neighbour);
        }
    }
    st.push(node);
}

vector<int> TopologicalSort(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    vector<bool> visited(n,0);
    stack<int> st;
    //creating a adjacency list
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
    
    //calling the topsort for all components of graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topSort(adjList, visited, st, i);
        }
    }

    vector<int> ans;
    while(!st.empty()){

        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    
    int n,m;
    cout <<"Enter the value of n & m : ";
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = TopologicalSort(edges, n, m);

    cout << "Topological Sort : ";
    for(auto val : topSort){
        cout << val << " ";
    }

    return 0;
}