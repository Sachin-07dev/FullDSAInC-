#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#include<algorithm>
using namespace std;

//using recursion

int solveRec(vector<int> &obstacle, int currlane, int currpos){
    int n = obstacle.size()-1;
    //base case
    if(currpos == n) return 0;
    //condition for going straight foreward
    if(obstacle[currpos+1] != currlane){
        return solveRec(obstacle,currlane,currpos+1);
    }else{
        //sideways - if obstacle is present
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
           if(currlane != i && obstacle[currpos] != i){
                    ans = min(ans, 1 + solveRec(obstacle, i, currpos));
            }
        }
        return ans;
    }
}

//using recursion + memoization - DP

int solveMem(vector<int> &obstacle, int currlane, int currpos,vector<vector<int>> &dp){
    int n = obstacle.size()-1;
    //base case
    if(currpos == n) return 0;

    if(dp[currlane][currpos] != -1) return dp[currlane][currpos];

    //condition for going straight foreward
    if(obstacle[currpos+1] != currlane){
        return solveMem(obstacle,currlane,currpos+1,dp);
    }else{
        //sideways - if obstacle is present
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
           if(currlane != i && obstacle[currpos] != i){
                    ans = min(ans, 1 + solveMem(obstacle, i, currpos,dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

//using tabulation method

int solveTab(vector<int> &obstacle){

    int n = obstacle.size()-1;
    vector<vector<int>> dp(4,vector<int>(n+1,1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currpos = n-1;currpos>=0;currpos--){
        for(int currlane =1;currlane <= 3; currlane++){

            if(obstacle[currpos+1] != currlane){
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }else{
                //sideways - if obstacle is present
                int ans = 1e9;
                for(int i=1;i<=3;i++){
                   if(currlane != i && obstacle[currpos] != i){
                        ans = min(ans, 1 + dp[i][currpos+1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
  }
int noOfJumps(vector<int> &obstacle){
    // return solveRec(obstacle,2,0);

    // vector<vector<int>> dp(4,vector<int> (obstacle.size()+1,-1));
    // return solveMem(obstacle,2,0,dp);

    return solveTab(obstacle);
}
int main(){

    int n;
    cin >> n;

    vector<int> obstacle(n);
    cout << "Enter the obstacle places: ";
    for(int i=0;i<n;i++){
        cin >> obstacle[i];
    }

    cout << "Total number of minimum jumps are: " << noOfJumps(obstacle);
    return 0;
}