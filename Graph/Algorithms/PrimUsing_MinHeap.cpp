#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<pair<int,int>,int>> vpair;
      //vector<pair<pair<u,v>,w>>
typedef vector<vector<int>> vect;
vpair primsAlgo(int n, int m, vect edges){
     
    //create a adjacecncy list;
    unordered_map<int, list<pair<int,int>>> adjList;
  //unordered_map<vertex --> list<pair<adjVertex, weightofEdges(src to adjVertex)>>>
  // for vertex ----> [<adjVertex, edgeWeight>]
  // for u = 0 --->  [<1,2>,<3,6>]
  // for u = 1 --->  [<0,2>,<2,3>,<3,8>,<4,5>]
  // for u = 2 --->  [<1,3>,<4,7>]
  // for u = 3 --->  [<0,6>,<1,8>]
  // for u = 4 --->  [<1,3>,<2,7>]
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    key[0] = 0;
    minHeap.push({0,0}); //(weight, vertex)

    while(!minHeap.empty()){
        pair<int,int> top = minHeap.top();
        minHeap.pop();

        int weight = top.first;
        int u = top.second;

        if(mst[u]) continue;
        mst[u] = true;

        for (auto neighbour : adjList[u]) {
            int adjVertex = neighbour.first;
            int edgeWeight = neighbour.second;
        
            if (!mst[adjVertex] && edgeWeight < key[adjVertex]) {
                key[adjVertex] = edgeWeight;
                parent[adjVertex] = u;
                minHeap.push(make_pair(edgeWeight, adjVertex));
            }           
        }
    }

    // Collect the result
    vector< pair<pair<int,int>, int> > result;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            result.push_back(make_pair(make_pair(parent[i], i), key[i]));
        }
    }
   return result;
}
int main(){

    int n,m;
    cout << "Ener the value of n & m :";
    cin >> n >> m;// 5 6

    vect edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});

        //input is : v u w
        /*           0 3 6 
                     0 1 2 
                     1 3 8
                     1 4 5 
                     1 2 3 
                     2 4 7  
         */
    
    }
    
    vector<pair<pair<int,int>,int>> ans = primsAlgo(n,m,edges);
    //vector<pair<pair<u,v>,w>>
    cout << "MST Edges: " << endl;
    for(int i=0;i<ans.size();i++){
        pair<int,int> edges = ans[i].first;
        int weight = ans[i].second;

        cout << edges.first << " - " << edges.second << " = " << weight << endl; 
    }
   return 0;
}