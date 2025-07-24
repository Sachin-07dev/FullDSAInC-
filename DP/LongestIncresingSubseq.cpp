#include<iostream>
#include<vector>
using namespace std;

//using recursion
int solveRec(vector<int>& nums,int n,int curr, int prev){

    //base case
    if(curr == n) return 0;

    //including case when the prev is -1 and nums[curr] > nums[prev]
    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveRec(nums,n,curr+1,curr);

    //exclude case
    int exclude = 0 + solveRec(nums,n,curr+1,prev);

    return max(include,exclude);
}

//using DP- rec + memoization
int solveMem(vector<int>& nums,int n, int curr, int prev, vector<vector<int>> &dp){

        //base case 
        if(curr == n) return 0;

        if(dp[curr][prev+1] != -1) 
            return dp[curr][prev+1];

        //include case - when the prev = -1 or curr ele is greater then prev ele
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            include = 1 + solveMem(nums,n,curr+1,curr,dp);

        int exclude = 0 + solveMem(nums,n,curr+1,prev,dp);
        dp[curr][prev+1] = max(include,exclude);

        return dp[curr][prev+1]; 
}

//using DP- tabulation method

int solveTab(vector<int> &nums,int n){

    vector<vector<int>> dp(n+1,vector<int> (n+1,0));

    for(int curr = n-1;curr>=0;curr--){
        for(int prev = curr-1;prev>=-1;prev--){
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr+1][curr+1];

            int exclude = 0 + dp[curr+1][prev+1];;
            dp[curr][prev+1] = max(include,exclude);
        }
    }
    return dp[0][0];
}

//space optimization in O(n) 
int solveTab2(vector<int> &nums,int n){

    vector<int> currR(n+1,0);
    vector<int> nextR(n+1,0);

    for(int curr = n-1;curr>=0;curr--){
        for(int prev = curr-1;prev>=-1;prev--){
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + nextR[curr+1];

            int exclude = 0 + nextR[prev+1];;
            currR[prev+1] = max(include,exclude);
        }
        nextR = currR;
    }
    return nextR[0];
}

//USING DP+BINARY SEARCH

int longSubseq(vector<int> &nums, int n){

    // return solveRec(nums,n,0,-1);

    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return solveMem(nums,n,0,-1,dp);

    return solveTab2(nums,n);
}
int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "Longest increasing Subsequence size is: " << longSubseq(nums,n);
}