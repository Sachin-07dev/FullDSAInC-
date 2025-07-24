#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveRec(vector<vector<int>> &mat, int i, int j, int &maxi){

    //base case
    if(i>=mat.size() || j >= mat[0].size()) return 0;

    //check for right
    int right = solveRec(mat, i,j+1,maxi);

    //check for diagonal
    int diagonal = solveRec(mat, i+1,j+1,maxi);

    //check for bottom
    int down = solveRec(mat, i+1,j,maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min({right, diagonal, down});
        maxi = max(ans, maxi);
        return ans;
    }else{
        return 0;
    }
}

//using dp-recursion + memoization
int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){

    //base case
    if(i>=mat.size() || j >= mat[0].size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //check for right
    int right = solveMem(mat, i,j+1,maxi,dp);

    //check for diagonal
    int diagonal = solveMem(mat, i+1,j+1,maxi,dp);

    //check for bottom
    int down = solveMem(mat, i+1,j,maxi,dp);

    if(mat[i][j] == 1){
        dp[i][j] = 1 + min({right, diagonal, down});
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }else{
        return dp[i][j] = 0;
    }
}

//dp-bottom -up approach
int solveTab(vector<vector<int>> &mat,int &maxi){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){

         //check for right
         int right = dp[i][j+1];

         //check for diagonal
         int diagonal = dp[i+1][j+1];

         //check for bottom
        int down = dp[i+1][j];
 
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min({right, diagonal, down});
            maxi = max(dp[i][j], maxi);
        }else{
            dp[i][j] = 0;
        }
    }
 }
 return dp[0][0];
}

int maxSquare(vector<vector<int>> &mat, int n, int m){

    // int maxi=0;
    // solveRec(mat, 0,0,maxi);
    // return maxi;

    // int maxi = 0;
    // vector<vector<int>> dp(n,vector<int> (m,-1));
    // solveMem(mat, 0,0,maxi,dp);
    // return maxi;

    int maxi =0;
    solveTab(mat, maxi);
    return maxi;


}

int main(){

    int n,m;
    cout << "Enter n & m: ";
    cin >> n >> m;

    vector<vector<int>> mat(n,vector<int>(m));
    cout << "Enter the matrix values: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    cout << "Largest Square Size is: " << maxSquare(mat,n,m);
    return 0;
}