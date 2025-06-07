#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Using Recursion

// int isMinCoins(int coins[], int amount, int n){
    
//     if(amount == 0) return 0;
//     if(amount < 0) return INT_MAX;

//     int mini = INT_MAX;
//     for(int i=0;i<n;i++){
//         int ans = isMinCoins(coins, amount-coins[i],n);

//         if(ans != INT_MAX){
//             mini = min(mini,1 + ans);
//         }
//     }
//     return mini;
// }

//------------------------------------------------------------------------

//using DP - recursion + memoization
// int isMinCoins(int coins[], int amount, int n, vector<int>& dp){
    
//     if(amount == 0) return 0;
//     if(amount < 0) return INT_MAX;

//     if(dp[amount] != -1) return dp[amount];

//     int mini = INT_MAX;
//     for(int i=0;i<n;i++){
//         int ans = isMinCoins(coins, amount-coins[i],n,dp);

//         if(ans != INT_MAX){
//             mini = min(mini,1 + ans);
//         }
//     }
//     dp[amount] = mini;
//     return mini;
// }
//--------------------------------------------------------------------------

// using tabulation method

int isMinCoins(int coins[], int amount, int n){

    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=amount;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j] >= 0 && dp[i-coins[j] != INT_MAX]){
                dp[i] = min(dp[i], 1+ dp[i-coins[j]]);
            }
        }
    }
    if(dp[amount] == INT_MAX){
        return -1;
    }
    return dp[amount];
}
int main(){

    int n;
    cout << "Enteer the no of coins: ";
    cin >> n;

    int coins[n];

    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the value of amount: ";
    cin >> amount;

    // vector<int> dp(amount+1,-1);
    // int ans = isMinCoins(coins,amount,n,dp);

    int ans = isMinCoins(coins,amount,n);
    cout << "The minimium coins used to make amount : ";
    if(ans == INT_MAX){
        cout << "-1";
    }else{
        cout << ans;
    }
    return 0;
}