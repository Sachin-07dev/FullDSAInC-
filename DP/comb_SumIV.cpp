#include<iostream>
#include<vector>
using namespace std;

//using recursion

int combSumIV(vector<int> &arr, int n, int target){

    //base case
    if(target == 0)
        return 1;
    
    if(target < 0) return 0;

    int ans =0 ;
    for(int i=0;i<arr.size();i++){
        ans += combSumIV(arr, n, target - arr[i]);
    }
    return ans;
}

//Using Dp-rec + mem

int combSumIVMem(vector<int> &arr, int n, int target, vector<int> &dp){

    //base case
    if(target == 0)
        return 1;
    
    if(target < 0) return 0;

    if(dp[target] != -1) return dp[target];

    int ans =0 ;
    for(int i=0;i<arr.size();i++){
        ans += combSumIV(arr, n, target - arr[i]);
    }
    dp[target] = ans;
    return dp[target];
}

//Using Tabulation method dp

int combSumIVTab(vector<int>& arr, int target){

    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for(int i=1;i<=target;i++){
        for(int j=0;j<arr.size();j++){
            if(i-arr[j] >= 0)
            dp[i] += dp[i-arr[j]];
        }
    }
    return dp[target];
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the data: ";
    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    vector<int> dp(target+1, -1);
    cout << " Total combination are: " << combSumIVMem(arr,n,target, dp);

    cout << " Total combination are: " << combSumIVTab(arr,target);
    return 0;
}