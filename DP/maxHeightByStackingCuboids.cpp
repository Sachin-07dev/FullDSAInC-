#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> base, vector<int> newBox){
    if(base[0] >= newBox[0] && base[1] >= newBox[1] && base[2] >= newBox[2])
        return true;
    return false;
}
int maxHeightCuboid(vector<vector<int>> &cuboids, int n){

    vector<int> currR(n+1,0);
    vector<int> nextR(n+1,0);

    for(int curr = n-1;curr>=0;curr--){
        for(int prev = curr-1;prev >= -1;prev--){
            int incl = 0;
            if(prev == -1 || check(cuboids[curr],cuboids[prev])){
                incl = cuboids[curr][2] + nextR[curr+1];
            }

            int excl = 0 + nextR[prev + 1];
            nextR[prev+1] = max(incl,excl);
        }
        nextR = currR;
    }
    return nextR[0];
}
int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;
     
    vector<vector<int>> cuboids(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cuboids[i][j];
        }
    }

    for(auto &a: cuboids){
        sort(a.begin(),a.end());
    }
    sort(cuboids.begin(),cuboids.end());

    cout << "Maxi height of the stacked cuboids is: " << maxHeightCuboid(cuboids,n); 
    return 0;
}

// // // recussion solution
// // class Solution {
// // public:
// //     bool isSafe(vector<int>&c1, vector<int>&c2){
// //         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
// //         return false;
// //     }
// //     int solve(vector<vector<int>>& cuboids, int curr, int prev){
// //         if(curr>=cuboids.size()) return 0;

// //         int include = 0;
// //         if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
// //             include = cuboids[curr][2] + solve(cuboids, curr+1, curr);
// //         }
// //         int exclude = 0 + solve(cuboids, curr+1, prev);
// //         int ans = max(include, exclude);
// //         return ans;
// //     }
// //     int maxHeight(vector<vector<int>>& cuboids) {
// //         for (auto& i : cuboids) {
// //             sort(i.begin(), i.end()); // sort individual cuboid dimensions
// //         }
// //         sort(cuboids.begin(), cuboids.end()); // sort all cuboids

// //         return solve(cuboids, 0, -1);
// //     }
// // };


// // top down memo
// class Solution {
// public:
//     bool isSafe(vector<int>&c1, vector<int>&c2){
//         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
//         return false;
//     }
//     int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
//         if(curr>=cuboids.size()) return 0;

//         if(dp[curr][prev+1] != -1){
//             return dp[curr][prev+1];
//         }
//         int include = 0;
//         if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
//             include = cuboids[curr][2] + solve(cuboids, curr+1, curr, dp);
//         }
//         int exclude = 0 + solve(cuboids, curr+1, prev, dp);
//         dp[curr][prev+1] = max(include, exclude);
//         return dp[curr][prev+1];
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for (auto& i : cuboids) {
//             sort(i.begin(), i.end()); // sort individual cuboid dimensions
//         }
//         sort(cuboids.begin(), cuboids.end()); // sort all cuboids
//         int n = cuboids.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(cuboids, 0, -1, dp);
//     }
// };

// // bottom up tab
// class Solution {
// public:
//     bool isSafe(vector<int>&c1, vector<int>&c2){
//         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
//         return false;
//     }
//     int solve(vector<vector<int>>& cuboids){
//         int n = cuboids.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         for(int curr = n-1; curr>=0; curr--){
//             for(int prev = curr-1; prev>=-1; prev--){
//                 int include = 0;
//                 if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
//                     include = cuboids[curr][2] + dp[curr+1][curr+1];
//                 }
//                 int exclude = 0 + dp[curr+1][prev+1];
//                 dp[curr][prev+1] = max(include, exclude);
//             }
//         }
//         return dp[0][-1+1];
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for (auto& i : cuboids) {
//             sort(i.begin(), i.end()); // sort individual cuboid dimensions
//         }
//         sort(cuboids.begin(), cuboids.end()); // sort all cuboids
        
//         return solve(cuboids);
//     }
// };

// bottom up
// class Solution {
// public:
//     bool isSafe(vector<int>&c1, vector<int>&c2){
//         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
//         return false;
//     }
//     int maxHeight(vector<vector<int>>& cuboids) {
//         for (auto& i : cuboids) {
//             sort(i.begin(), i.end()); // sort individual cuboid dimensions
//         }
//         sort(cuboids.begin(), cuboids.end()); // sort all cuboids
//         int n = cuboids.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         for(int curr = n-1; curr>=0; curr--){
//             for(int prev = curr-1; prev>=-1; prev--){
//                 int include = 0;
//                 if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
//                     include = cuboids[curr][2] + dp[curr+1][curr+1];
//                 }
//                 int exclude = 0 + dp[curr+1][prev+1];
//                 dp[curr][prev+1] = max(include, exclude);
//             }
//         }
//         return dp[0][-1+1];
//     }
// };

// // space optimal
// class Solution {
// public:
//     bool isSafe(vector<int>&c1, vector<int>&c2){
//         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
//         return false;
//     }
//     int maxHeight(vector<vector<int>>& cuboids) {
//         for (auto& i : cuboids) {
//             sort(i.begin(), i.end()); // sort individual cuboid dimensions
//         }
//         sort(cuboids.begin(), cuboids.end()); // sort all cuboids
//         int n = cuboids.size();
//         vector<int> prev1(n+1, 0);
//         vector<int> curr1(n+1, 0);
//         for(int curr = n-1; curr>=0; curr--){
//             for(int prev = curr-1; prev>=-1; prev--){
//                 int include = 0;
//                 if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
//                     include = cuboids[curr][2] + prev1[curr+1];
//                 }
//                 int exclude = 0 + prev1[prev+1];
//                 curr1[prev+1] = max(include, exclude);
//             }
//             prev1 = curr1;
//         }
//         return prev1[-1+1];
//     }
// };


// // space optimal
// class Solution {
// public:
//     bool isSafe(vector<int>&c1, vector<int>&c2){
//         if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
//         return false;
//     }
//     int maxHeight(vector<vector<int>>& cuboids) {
//         for (auto& i : cuboids) {
//             sort(i.begin(), i.end()); // sort individual cuboid dimensions
//         }
//         sort(cuboids.begin(), cuboids.end()); // sort all cuboids
//         int n = cuboids.size();
//         // vector<int> prev1(n+1, 0);
//         vector<int> curr1(n+1, 0);
//         for(int curr = n-1; curr>=0; curr--){
//             for(int prev =-1; prev<=curr-1; prev++){
//                 int include = 0;
//                 if(prev == -1 || isSafe(cuboids[prev], cuboids[curr])){
//                     include = cuboids[curr][2] + curr1[curr+1];
//                 }
//                 int exclude = 0 + curr1[prev+1];
//                 curr1[prev+1] = max(include, exclude);
//             }
//             // prev1 = curr1;
//         }
//         return curr1[-1+1];
//     }
// };