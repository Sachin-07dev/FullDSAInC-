// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

#include<iostream>
#include<vector>
using namespace std;

int perfectSq(int n){

    if(n == 0) return 0;

    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans,1+perfectSq(n-i*i));
    }
    return ans;
}

int perfectSqMem(int n, vector<int> &dp){

    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans,1+perfectSq(n-i*i));
    }
    dp[n] = ans;
    return dp[n];
}

int perfectSpTab(int n){

    vector<int> dp(n+1,0);

    dp[0] = 0;

    for(int i=1;i<=n;i++){
       for(int j=1; j*j <= n;j++){
         if(i - j*j >= 0)
            dp[i] = min(dp[i], dp[i-j*j]);
       }
    }
    return dp[n];
}
int main(){

    int n;
    cin >> n;

   cout << "Least No of perfect square that sum to " << n << " using recursion is: " << perfectSq(n) << endl;

   vector<int> dp(n+1,-1);
   cout << "Least No of perfect square that sum to " << n << " usinf Dp(memoization method)  is : " << perfectSqMem(n,dp) << endl;

   return 0;
}