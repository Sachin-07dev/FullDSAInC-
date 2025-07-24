// You have a convex n-sided polygon where each vertex has an integer value.
// You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

// Polygon triangulation is a process where you divide a polygon into a 
//set of triangles and the vertices of each triangle must also be 
//vertices of the original polygon. Note that no other shapes other than triangles 
//are allowed in the division. This process will result in n - 2 triangles.

// You will triangulate the polygon. For each triangle, the weight of that triangle is 
//the product of the values at its vertices. The total score of the triangulation
// is the sum of these weights over all n - 2 triangles.

// Return the minimum possible score that you can achieve with some triangulation /
//of the polygon.
// Example 1:

// Input: values = [1,2,3]
// Output: 6

// Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

// Example 2:
// Input: values = [3,7,4,5]
// Output: 144

// Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
// The minimum score is 144.

// Example 3:
// Input: values = [1,3,1,4,1,5]
// Output: 13

// Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
// Constraints:

// n == values.length
// 3 <= n <= 50
// 1 <= values[i] <= 100

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

//recursive way

int minPossibleScore(int n, vector<int> &values,int i, int j){

    //baase case
    if(i+1 == j) return 0;

    int ans = INT_MAX;
    for(int k=i+1;k<j;k++){
        ans = min(ans, values[i]*values[j]*values[k] + minPossibleScore(n,values,i,k)
         + minPossibleScore(n,values,k,j));
    }
    return ans;
}

int minPossibleScoreMem(int n, vector<int> &values,int i, int j,vector<vector<int>> &dp){

    //baase case
    if(i+1 == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1;k<j;k++){
        ans = min(ans, values[i]*values[j]*values[k] + minPossibleScoreMem(n,values,i,k,dp)
         + minPossibleScoreMem(n,values,k,j,dp));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int minPossibleScoreTab(vector<int> &values){

    int n = values.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int i=n-1;i>=0;i++){
        for(int j=i+2;j>=0;j++){

            int ans = INT_MAX;
            for(int k=i+1;k<j;k++){
            ans = min(ans, values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int main(){

    int n;
    cin >> n;

    vector<int> values(n);
    for(int i=0;i<n;i++){
        cin >> values[i];
    }

    cout << "Minimum possible score(Recursion): " << minPossibleScore(n,values,0,n-1);

    vector<vector<int>> dp(n, vector<int>(n,-1));
    cout << "Minimum possible score(Memoization): " << minPossibleScoreMem(n,values,0,n-1,dp);



    return 0;
}