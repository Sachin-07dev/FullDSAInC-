#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//simple recursiv way
int solve(int weight[], int values[],int index, int capacity){
    
    //base case
    // if only one item to steal, then just compare its weight to the knapsack capacity
    if(index == 0){
        if(weight[0] <= capacity)
            return values[0];
        else
            return 0;
    }


    int include = 0, exclude = 0;
    if(weight[index] <= capacity)
        include = values[index] + solve(weight, values, index-1,capacity-weight[index]);
    
    exclude = 0 + solve(weight, values, index-1,capacity);
   
    int ans = max(include, exclude);
    return ans;
}

// using DP- recursion + memoizzation
int solveMem(int weight[], int values[],int index, int capacity, vector<vector<int>>& dp){
    
    //base case
    // if only one item to steal, then just compare its weight to the knapsack capacity
    if(index == 0){
        if(weight[0] <= capacity)
            return values[0];
        else
            return 0;
    }

    if(dp[index][capacity] == -1){
        return dp[index][capacity];
    }
    int include = 0, exclude = 0;
    if(weight[index] <= capacity)
        include = values[index] + solveMem(weight, values, index-1,capacity-weight[index],dp);
    
    exclude = 0 + solveMem(weight, values, index-1,capacity,dp);
   
    dp[index][capacity]= max(include, exclude);
    return dp[index][capacity];
}

//Using tabulaion method - DP
int solveTab(int weight[], int values[],int n, int capacity){
    
    vector<vector<int>> dp(n,vector<int>(capacity,-1));

    for(int w=weight[0];w<=capacity;w++){

        if(weight[0] <= capacity)
            dp[0][w] = values[0];
        else
            dp[0][w] = 0;
    }

    for(int index = 1;index < n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0,exclude = 0;
            if(weight[index] <= w){
                include = values[index] + dp[index-1][w-weight[index]];
            }

            exclude = 0 + dp[index-1][w];

            dp[index][w] = max(include,exclude);
        }
    }
     return dp[n-1][capacity];
}
int knapsack(int weight[], int values[],int n, int capacity){
    // vector<vector<int>> dp(n,vector<int>(capacity,-1));
    // return solveMem(weight, values, n-1,capacity,dp);

    return solveTab(weight, values, n,capacity);

}
int main(){

    int n;
    cin >> n;

    int weight[n],values[n];
    cout << "Enter the weights and its values: ";
    for(int i=0;i<n;i++){
        cin >> weight[i] >> values[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "The maximum values is : " << knapsack(weight,values,n,capacity);
    return 0;
}