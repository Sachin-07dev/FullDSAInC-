// There are n cities, numbered from 0 to n-1. Given the array edges, 
//where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge 
//between cities ai and bi, and given the integer T (distance Threshold).

// Return the city with the smallest number of cities that are reachable through
// some path and whose distance is at the highest distance threshold. If there are
// multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is
// equal to the sum of the edge weights along that path.

// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], T = 4
// Output: 3

// Explanation: The figure above describes the graph. 
// The neighboring cities at a T = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a T = 4, but we have to return city 3 since it has the greatest number.

// Example 2:
// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], T= 2
// Output: 0

// Explanation: The figure above describes the graph. 
// The neighboring cities at a T = 2 for each city are:
// City 0 -> [City 1] 
// City 1 -> [City 0, City 4] 
// City 2 -> [City 3, City 4] 
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3] 
// The city 0 has 1 neighboring city at a T = 2.

// Input format :
// The input consists of the following:

// The first line of input consists of integer n, representing the number of cities.
// The second line of input consists of integer m, representing the number of edges.
// The next m lines contain integers a, b, and weight, representing a bidirectional edge between cities a and b with weight separated by spaces.
// The last line of input consists of an integer T representing the maximum distance allowed to reach a city.

// Output format :
// The output prints an integer representing the index of the city with the 
//smallest number of reachable cities within the given distance threshold. 
//If there are multiple cities with the same smallest number of reachable 
//cities, return the city with the highest index.

// Refer to the sample output for format specifications.

// Code constraints :
// 2 ≤ n ≤ 100
// 1 ≤ edges.length ≤ n * (n - 1) / 2
// edges[i].length == 3
// 0 ≤ ai < bi < n
// 1 ≤ weighti, T ≤ 104
// All pairs (ai, bi) are distinct.

// Sample test cases :
// Input 1 :
// 4
// 4
// 0 1 3
// 1 2 1
// 1 3 4
// 2 3 1
// 4
// Output 1 :
// 3

// Input 2 :
// 5
// 6
// 0 1 2
// 0 4 8
// 1 2 3
// 1 4 2
// 2 3 1
// 3 4 1
// 2
// Output 2 :
// 0

#include<bits/stdc++.h>
using namespace std;

int countReachableCities(int src, unordered_map<int, list<pair<int,int>>> &adjList, int n, int T){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        int citydist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(citydist > dist[node]) continue;

        for(auto neighbour : adjList[node]){
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if(dist[node] + edgeWeight < dist[adjNode]){
                dist[adjNode] = dist[node] + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(i != src && dist[i] <= T){
            cnt++;
        }
    }
    return cnt; 
}
int findCity(int n, int m, vector<vector<int>> &edges, int T){
    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    int minCnt = INT_MAX;
    int result;

    for(int city = 0; city < n;city++){
        int reachable = countReachableCities(city, adjList, n,T);
        if(reachable <= minCnt){
            minCnt = reachable;
            result = city;
        }
    }
    return result;
}
int main(){

    int n,m;
    cout << "Enter n&m: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    int T;
    cin >> T;

    int result = findCity(n,m,edges,T);
    cout << result;

    return 0;
}