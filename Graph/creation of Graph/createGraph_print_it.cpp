#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Edges;

Edges createAdjacencyGraph(int n, int m, Edges &edges){

    Edges solution(n);

    for (int i = 0; i < n; i++)
    {
        solution[i].push_back(i);
    }

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        solution[u].push_back(v);
        solution[v].push_back(u);
    }

    return solution;
    
}
int main(){
    
    int n;
    cin >> n;

    int m;
    cin >> m;

    Edges edges(m,{0,0});

    for(int i=0;i<m;i++){
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    Edges solution = createAdjacencyGraph(n,m,edges);

    for(auto i : solution){
           for(auto j : i){
                cout << j << " ";
           }cout << endl;
    }
    return 0;
}