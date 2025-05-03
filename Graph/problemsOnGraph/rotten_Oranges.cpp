#include<bits/stdc++.h>
using namespace std;

void bfs(int &time, queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &vis){

    int drow[] = { -1, 0, 1, 0};
    int dcol[] = { 0, 1, 0, -1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == 0 && 
              grid[nrow][ncol] == 1){
                 q.push({{nrow,ncol}, t+1});
                 vis[nrow][ncol] = 2;          
            }
        }
    }
}
int rottenOranges(int n, int m, vector<vector<int>> &grid){
     
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }else{  
                vis[i][j] = 0;
            }
        }
    }
    int time = 0;
    bfs(time, q,grid,n,m,vis);
    
    // check if is there any fresh orange left and if return -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }
    return time;
}
int main(){

    int n,m;
    cout << "Enter n & m: ";
    cin >> n >> m;

    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
    int ans = rottenOranges(n,m,grid);
    cout << "The time consumed is: " << ans << endl;
    return 0;
}