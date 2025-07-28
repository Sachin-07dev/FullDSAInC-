#include<bits/stdc++.h>
using namespace std;

//using recursion
int solveRec(int index, int endindex,vector<int> &slices, int n){

    if(n==0 || index > endindex) return 0;

    int incl = slices[index] + solveRec(index+2,endindex,slices,n-1);
    int excl = 0 + solveRec(index+1,endindex,slices,n);
    return max(incl, excl);
}

//using memoization
int solveMem(int index, int endindex,vector<int> &slices, int n,vector<vector<int>> &dp){

    if(n==0 || index > endindex) return 0;

    if(dp[index][n] != -1) return dp[index][n];

    int incl = slices[index] + solveMem(index+2,endindex,slices,n-1,dp);
    int excl = 0 + solveMem(index+1,endindex,slices,n,dp);
    return dp[index][n] = max(incl, excl);
}

//Using tabulation method

int solveTab(vector<int> &slices,int k){

    vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

    for(int index = k-2;index>=0;index--){
        for(int n = 1;n<=k/3;n++){

            int incl = slices[index] + dp1[index+2][n-1];
            int excl = 0 + dp1[index+1][n];

            dp1[index][n] = max(incl,excl);
        }
    }
    int case1 = dp1[0][k/3];

    for(int index = k-1;index>=1;index--){
        for(int n = 1;n<=k/3;n++){

            int incl = slices[index] + dp1[index+2][n-1];
            int excl = 0 + dp1[index+1][n];

            dp1[index][n] = max(incl,excl);
        }
    }
    int case2 = dp1[1][k/3];

    return max(case1,case2);
}


int maxSlices(vector<int> &slices, int k){

    // int case1 = solveRec(0,k-2,slices,k/3);
    // int case2 = solveRec(1,k-1,slices,k/3);
    // return max(case1,case2);

    // vector<vector<int>> dp1(k,vector<int>(k,-1));
    // int case1 = solveMem(0,k-2,slices,k/3,dp1);
    // vector<vector<int>> dp2(k,vector<int>(k,-1));
    // int case2 = solveMem(0,k-2,slices,k/3,dp2);
    // return max(case1,case2);

    return solveTab(slices,k);
}
int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> slices(n);
    for(int i=0;i<n;i++){
        cin >> slices[i];
    }

    cout << "Maximum no of slices you can eat are: " << maxSlices(slices,n);
    return 0;

}