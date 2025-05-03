#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>&image, int n, int m, int color, int iniColor){
    ans[row][col] = color;

    int drow[] = {-1,0,1,0};
    int dcol[] = { 0,1,0,-1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m &&
         ans[nrow][ncol] != color && image[nrow][ncol] == iniColor){
            dfs(nrow, ncol, ans, image,n,m,color, iniColor);
        }
    }
}
vector<vector<int>> floodFill(int n, int m,int sr, int sc, vector<vector<int>> &image, int color){
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    dfs(sr,sc,ans,image,n,m,color,iniColor);
    return ans;
}
int main(){
    
    int n,m;
    cout << "Enter the value of n & m: ";
    cin >> n >> m;

    vector<vector<int>> image(n,vector<int>(m));
    int sr,sc,color;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> image[i][j];
        }
    }
    cout << "Enter sr & sc: ";
    cin >> sr >> sc;
    cout << "Enter the value of color: ";
    cin >> color;
    vector<vector<int>> ans = floodFill(n,m,sr,sc,image,color);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}