#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// int kthLargestSum(vector<int> &arr, int K){

//     vector<int> storeSum;
//     for(int i=0;i<arr.size();i++){
//         int sum = 0;
//         for(int j=i;j<arr.size();j++){
//             sum += arr[j];
//             storeSum.push_back(sum);
//         }
//     }

//     sort(storeSum.begin(), storeSum.end());
//     return storeSum[storeSum.size()-K];
// }

int kthLargestSum(vector<int> &arr, int k){

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j=i;j<arr.size();j++){
            sum += arr[j];
            if(minHeap.size() < k){
                minHeap.push(sum);
            }else{
                if(sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main(){

    int n;
    cout << "Enter: ";
    cin >> n;

    vector<int> arr;
    int data;
    for(int i=0;i<n;i++){
        cin >> data;
        arr.push_back(data);
    }
    
    int k;
    cout << "Enter k: ";
    cin >> k;

    int ans = kthLargestSum(arr,k);
    cout << "The Kth Largest sum of the array is: " << ans;

    return 0;
}