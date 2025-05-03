#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkastra(int n, int m, int start, vector<vector<int>> &edges){

    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(distance > dist[node]){
            continue;
        }

        for(auto neighbour : adjList[node]){
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if(dist[node] + edgeWeight < dist[adjNode]){
                dist[adjNode] = dist[node] + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cout << "Enter the value of n (nodes) and m (edges): ";
    cin >> n >> m;

    vector<vector<int>> edges;
    cout << "Enter u, v and w for each edge:\n";
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> path = Dijkastra(n, m, start, edges);

    cout << "\nShortest distances from node " << start << ":\n";
    for(int i=0; i<n; i++){
        if(path[i] == INT_MAX)
            cout << "Node " << i << " is unreachable." << endl;
        else
            cout << "Distance to node " << i << " = " << path[i] << endl;
    }

    return 0;
}
