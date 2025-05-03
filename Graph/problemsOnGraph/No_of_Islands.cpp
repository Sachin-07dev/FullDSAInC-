#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
      
    vis[row][col] = 1;
    
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    q.push({row,col});
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int rw = q.front().first;
        int co = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = rw + drow[i];
            int ncol = co + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
              && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
              }
        }
    }
}
int noOfIslands(int n, int m, vector<vector<char>> &grid){
    
    vector<vector<int>> visited(n, vector<int>(m,0));
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 0 && grid[i][j] == '1'){
                bfs(i,j,visited,grid);
                cnt++;
            } 
        }
    }
    return cnt; 
}
int main(){
    
    int n,m;
    cout << "Enter the value of n & m: ";
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));
    cout << "Enter the data in grid: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    int result = noOfIslands(n,m,grid);
    cout << "The possible islands are : "<< result;

    return 0;
}