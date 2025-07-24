#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int minCostToBuyTicketRec(int n, vector<int> &days, vector<int> &costs, int index){

   // base case
    if(index >= n) return 0;

    //1-day
    int options1 = costs[0] +  minCostToBuyTicketRec(n, days,costs,index+1);       

    //7-day
    int i;
    for(i = index; i<n && days[i] < days[index] + 7;i++);
    int options2 = costs[1] +  minCostToBuyTicketRec(n, days,costs,i);

    //30-days
    for(i = index; i<n && days[i] < days[index] + 30;i++);
    int options3 = costs[2] +  minCostToBuyTicketRec(n, days,costs,i);

    return min({options1, options2, options3});

}

//using dp -rec + mem
int minCostToBuyTicketMem(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){

   // base case

    if(index >= n) return 0;

    if(dp[n] != -1) return dp[n];

    //1-day
    int options1 = costs[0] +  minCostToBuyTicketRec(n, days,costs,index+1);       

    //7-day
    int i;
    for(i = index; i<n && days[i] < days[index] + 7;i++);
    int options2 = costs[1] +  minCostToBuyTicketRec(n, days,costs,i);

    //30-days
    for(i = index; i<n && days[i] < days[index] + 30;i++);
    int options3 = costs[2] +  minCostToBuyTicketRec(n, days,costs,i);

    dp[n] = min({options1, options2, options3});
    return dp[n];
}

//using Dp-Tabulation
int minCostToBuyTicketTab(int n, vector<int> &days, vector<int> &costs, int index){

    vector<int> dp(n+1,INT_MAX);

    dp[n] = 0;

    for(int k=n-1;k>=0;k--){
        
        //1-day
        int options1 = costs[0] +  dp[k+1];       

        //7-day
        int i;
        for(i = k; i<n && days[i] < days[k] + 7;i++);
        int options2 = costs[1] + dp[i];

        //30-days
        for(i = k; i<n && days[i] < days[k] + 30;i++);
        int options3 = costs[2] +  dp[i];

        dp[k] = min({options1, options2, options3});
    }
  return dp[0];

}

int main(){


    int n;
    cout << "Enter n: ";
    cin >> n;
    
    vector<int> days(n);
    cout << "Enter the days to travel on: ";
    for(int i=0;i<n;i++){
        cin >> days[i];
    }

    vector<int> costs(3);
    cout << "Enter the costs: ";
    for(int i=0;i<3;i++){
        cin >> costs[i];
    }

    cout << "Minimum cost of tickets are(recursion): " << minCostToBuyTicketRec(n,days,costs,0) << endl;

    vector<int> dp(n+1,-1);
    cout << "Minimum cost of tickets are(through Dp-memozaition): " << minCostToBuyTicketRec(n,days,costs,0) << endl;

    cout << "Minimum cost of tickets are(Dp-Tabulation): " << minCostToBuyTicketTab(n,days,costs,0) << endl;

    return 0;
    
}