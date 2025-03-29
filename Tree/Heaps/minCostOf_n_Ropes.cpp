#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findMinCost(vector<int> arr, int n){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();
    
        int sum = a+b;
        cost += sum;
    
        pq.push(sum);
    }
    return cost;
}
int main(){

    vector<int> arr;

    int temp;
    cout << "Enter the element of array: ";
    cin >> temp;
    while(temp != -1){
       arr.push_back(temp);
       cin >> temp;
    }

    int ans = findMinCost(arr, arr.size());
    cout << "The cost of Ropes is: " << ans;

    return 0;
}