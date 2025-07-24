// A chef has collected data on the satisfaction level of his n dishes.
// Chef can cook any dish in 1 unit of time.
// Like-time coefficient of a dish is defined as the time taken to cook that dish 
//including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
// Example 1:

// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
// Example 2:

// Input: satisfaction = [4,3,2]
// Output: 20
// Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
// Example 3:

// Input: satisfaction = [-1,-4,-5]
// Output: 0
// Explanation: People do not like the dishes. No dish is prepared.

#include<iostream>
#include<vector>
using namespace std;

//using recursion

int solveRec(vector<int> &satisfaction, int index, int time){
    int n = satisfaction.size();

    //base case
    if(index == n) return 0;

    int include = satisfaction[index]*(time+1) + solveRec(satisfaction,index+1,time+1);
    int exclude = 0 + solveRec(satisfaction,index+1,time);

    return max(include,exclude);
}

//using DP- recursion + memoization
int solveMem(vector<int> &satisfaction, int index, int time,vector<vector<int>> &dp){
    int n = satisfaction.size();

    //base case
    if(index == n) return 0;

    if(dp[index][time] != -1) return dp[index][time];

    int include = satisfaction[index]*(time+1) + solveMem(satisfaction,index+1,time+1,dp);
    int exclude = 0 + solveMem(satisfaction,index+1,time,dp);

    dp[index][time] = max(include,exclude);
    return dp[index][time];
}

//using DP- tabulation method

int solveTab(vector<int> &satisfaction){
    int n = satisfaction.size();

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int index = n-1;index>=0;index--){
        for(int time = index;time>=0;time--){

            int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
            int exclude = 0 + dp[index+1][time];

            dp[index][time] = max(include,exclude);
        }
    }
    return dp[0][0];
}

//In O(n) space complexity using tabulation method

int solveTab2(vector<int> &satisfaction){

    int n = satisfaction.size();
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){

            int include = satisfaction[index]*(time+1) + next[time+1];
            int exclude = 0 + next[time];
            
            curr[time] = max(include,exclude);
        }
        next = curr;
    }
    return next[0];
}
int maxSum(vector<int> &satisfaction){

  //return solveRec(satisfaction,0,0);
    int n = satisfaction.size();
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return solveMem(satisfaction,0,0,dp);

    cout << "Max Sum(sTab): " << solveTab(satisfaction) << endl;
    cout << "Max Sum(sTab2): " << solveTab2(satisfaction) << endl;
    return solveTab(satisfaction);
    
}

int main(){

    int n;
    cout << "Enter the n: ";
    cin >> n;
    vector<int> satisfaction(n);

    for(int i=0;i<n;i++) cin >> satisfaction[i];

    cout << "Max sum obtained is: " << maxSum(satisfaction);
    return 0;
}