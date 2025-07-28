#include<bits/stdc++.h>
using namespace std;

//Using recusion
int solveRec(int dice, int faces, int target){

    if(dice == 0 && target != 0) return 0;
    if(target == 0 && dice != 0) return 0;
    if(target < 0) return 0;
    if(dice ==0 && target == 0) return 1;

    int ans = 0;
    for(int i=1;i<=faces;i++){
        ans = ans + solveRec(dice-1,faces,target-i);
    }
    return ans;
}

//using memoization + recursion -dp

int solveMem(int dice, int faces, int target , vector<vector<int>> &dp){

    if(dice == 0 && target != 0) return 0;
    if(target == 0 && dice != 0) return 0;
    if(target < 0) return 0;
    if(dice ==0 && target == 0) return 1;

    if(dp[dice][target] != -1) return dp[dice][target];

    int ans = 0;
    for(int i=1;i<=faces;i++){
        ans = ans + solveMem(dice-1,faces,target-i,dp);
    }
    return dp[dice][target] = ans;
}

//Using tabulation method

int solveTab(int dice, int faces, int target){

    vector<vector<int>> dp(dice+1,vector<int>(target+1,0));
    dp[0][0] = 1;

    for(int d = 1;d<=dice;d++){
        for(int t = 1;t<= target; t++){

            int ans = 0;
            for(int i=1;i<=faces;i++){
                if(t-i >= 0)
                    ans = ans + dp[d-1][t-i];
            }
            dp[d][t] = ans;
        }
    }
    return dp[dice][target];
}

//Space optimizing solution
// dp[dice][target] ---> dp[dice-1][target-i]
// replace dp[dice] with curr vector and dp[dice-1] with prev name vector

int solveTabSO(int dice, int faces, int target){

    vector<int> curr(target+1,0);
    vector<int> prev(target+1,0);

    prev[0] = 1;
    for(int d = 1;d<=dice;d++){
        for(int t = 1;t<= target; t++){

            int ans = 0;
            for(int i=1;i<=faces;i++){
                if(t-i >= 0)
                    ans = ans + prev[t-i];
            }
            curr[t] = ans;
        }
        prev = curr;
    }
    return curr[target];

}

int diceRollsWithTarget(int dice, int faces, int target){
    // return solveRec(dice,faces,target);

    // vector<vector<int>> dp(dice+1,vector<int>(target+1,-1));
    // return solveMem(dice, faces, target,dp);

    return solveTab(dice, faces,target);
}
int main(){

    int dice,faces,target;
    cin >> dice >> faces >> target;

    cout << "Minimum number of dice rolls with sum " << target << 
    " is: " << diceRollsWithTarget(dice,faces,target);
}