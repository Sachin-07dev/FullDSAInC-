#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

//Using recursion
int noOfWays(int n, int k){

    if(n==1) return k;
    if(n==2) return add(k, mul(k, k-1));

    int ans = add(mul(noOfWays(n-2,k),k-1), mul(noOfWays(n-1,k),k-1));

    return ans;
}

//using DP-rec + memoization
int noOfWays(int n, int k, vector<int> &dp){

    if(n==1) return k;
    if(n==2) return add(k, mul(k, k-1));

    if(dp[n] != -1) return dp[n];
    dp[n] = add(mul(noOfWays(n-2,k),k-1), mul(noOfWays(n-1,k),k-1));

    return dp[n];
}

//using tabulation
int noOfWaysTab(int n, int k){

    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i=3;i<=n;i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
//using pointers
int noOfWaysUsingPointer(int n, int k){

    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i=3;i<=n;i++){
        int ans = add(mul(prev2,k-1),mul(prev1,k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int main(){

    // int n,k;
    // cin >> n >> k;
    // cout << "Number of ways the fence can be printed is: " << noOfWays(n,k);

    // int n,k;
    // cin >> n >> k;
    // vector<int> dp(n+1,-1);
    // cout << "Number of ways the fence can be printed is: " << noOfWays(n,k,dp);
    int n,k;
    cin >> n >> k;
    cout << "Number of ways the fence can be printed is: " << noOfWaysUsingPointer(n,k);
    return 0;
}