#include<bits/stdc++.h>
using namespace std;
 
void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int node ){
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(adjList, visited, neighbour);
        }
    }
}
int noOfProvinces(vector<vector<int>> &isConnected, int n){
    unordered_map<int, list<int>> adjMat;
    vector<bool> visited(n,false);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j] == 1 && i != j){
                adjMat[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(visited[i]){
            cnt++;
            dfs(adjMat, visited, i);
        }
    }
    return cnt;
}
int main(){

    
    int n,m;
    cout << "Enter the value of n & m: ";
    cin >> n >> m;

    vector<vector<int>> isConnected(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> isConnected[i][j];
        }
    }

    int result = noOfProvinces(isConnected,n);
    cout << "Total number of Provinces are: " << result << endl;

    return 0;
}