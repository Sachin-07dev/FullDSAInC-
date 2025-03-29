// There are some gas stations along a circular route. You are given two integer arrays gas[] 
//denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling 
//to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty
// tank from one of the gas stations. Return the index of the starting gas station if it's possible 
//to travel around the circuit without running out of gas at any station in a clockwise direction.
// If there is no such starting station exists, return -1.

// Note: If a solution exists, it is guaranteed to be unique.

// Examples:

// Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
// Output: 2
// Explanation: It is possible to travel around the circuit from station at index 2.
// Amount of gas at station 2 is (7 - 3) 4.
// Amount of gas at station 3 is (4 + 4 - 5) 3.
// Amount of gas at station 0 is (3 + 4 - 6) 1.
// Amount of gas at station 1 is (1 + 5 - 6) 0.
// Input: gas[] = [1, 2, 3, 4, 5], cost[] = [3, 4, 5, 1, 2]
// Output: 3
// Explanation: It is possible to travel around the circuit from station at index 3.
// Amount of gas at station 3 is (4 - 1) 3.
// Amount of gas at station 4 is (3 + 5 - 2) 6.
// Amount of gas at station 0 is (6 + 1 - 3) 4.
// Amount of gas at station 1 is (4 + 2 - 4) 2.
// Amount of gas at station 2 is (2 + 4 - 5) 1.
// Input: gas[] = [3, 9], cost[] = [7, 6]
// Output: -1
// Explanation: There is no gas station to start with such that you can complete the circuit.
// Constraints:
// 1 ≤ gas.size(), cost.size() ≤ 106
// 1 ≤ gas[i], cost[i] ≤ 103

#include<bits/stdc++.h>
using namespace std;

class solution{
   public:
     int startstation(vector<int>& gas, vector<int>& cost){
         
         int deficit = 0;
         int balance = 0;
         int start = 0;
         int n = gas.size();

         for(int i=0;i<n;i++){
            balance += gas[i]-cost[i];
            if(balance < 0){
                deficit += balance;
                start = i+1;
                balance = 0;  
            }
         }

         if(deficit + balance >=0){
            return start;
         }else{
            return -1;
         }
     }
};     

int main(){

    int N;
    cout << "Enter no of cases:";
    cin >> N;
    while(N--){
        int n;
        cout << "Enter the no of gas station:";
        cin >> n;
        
        vector<int> gas(n);
        vector<int> cost(n);

        cout << "Enter the amount gas each station have:";
        for(int i=0;i<n;i++){
            cin >> gas[i];
        }

        cout << "Enter the travelling cost to next station:";
        for(int i=0;i<n;i++){
            cin >> cost[i];
        }

        solution sol;
        cout << sol.startstation(gas,cost) << endl;
    }
    return 0;
}