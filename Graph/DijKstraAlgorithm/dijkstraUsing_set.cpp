#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkstas(int n, int m, int src , vector<vector<int>>&edges){
    //create a adjacancy list
    //unordered_map<vertex, list<pair<vertex, distance(src to vertex)>>> adjList;
    unordered_map<int, list<pair<int,int>>> adjlist;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }

    vector<int> dist(n,INT_MAX);
    //ser<pair<distance,node>> set;
    set<pair<int,int>> st;
    
    dist[src] = 0;
    st.insert({0,src});

    while(!st.empty()){

        //fetch the top
        pair<int,int> top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;

        //remove the top pair
        st.erase(st.begin());

        //traverse all the neighbour of top pair
        for(auto neighbour : adjlist[topNode]){
             //find record

             if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find({dist[neighbour.first],neighbour.first});

             //check record and if find then erase
             if(record != st.end()){
                st.erase(record);
             }
             //update the distance if the dist[neighbour] is greater
             dist[neighbour.first] = nodeDistance + neighbour.second;

             //insert the new pair in the set
             st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
     // return ans as the distance array
     return dist;
}
int main(){
    
    int n,m;
    cout << "Enter the number of vertecs and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }    

    vector<int> sPath = Dijkstas(n,m,src,edges);

    cout << "Shortest distance from source:" << endl;
    for(int i=0;i<n;i++){
        if(sPath[i] == INT_MAX){
            cout << "Vertex " << i << " is unreachable." << endl;
        }else{
            cout << "Shortest Distance to vertex " << i << " is " << sPath[i] << endl;
        }
    }
    
    return 0;
}