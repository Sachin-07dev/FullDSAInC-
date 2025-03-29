// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) 
//subarray of arr. Since the answer may be large, return the answer modulo 1e9 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

#include<bits/stdc++.h>
using namespace std;

vector<int> findnse(vector<int> arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
     while(!st.empty() && arr[st.top()] >= arr[i]){
         st.pop();
     }

    nse[i] = (st.empty())?n:st.top();
    st.push(i);
    }

    return nse;
 }

 vector<int> findnpe(vector<int> arr){
    int n = arr.size();
    vector<int> npe(n);
    stack<int>st;

    for(int i=0;i<n;i++){
     while(!st.empty() && arr[st.top()] > arr[i]){
         st.pop();
     }

    npe[i] = (st.empty())?-1:st.top();
    st.push(i);
    }

    return npe;
 }

int miniSubarraySum(vector<int> arr) {
    int n = arr.size();
    int total = 0;
    int mod = (int)(1e9+7);

    vector<int> nse = findnse(arr);
    vector<int> npe = findnpe(arr);

    for(int i=0;i<n;i++){
        long long left = i - npe[i];
        long long right = nse[i] - i;

        total = (total + (left * right % mod * arr[i] % mod)) % mod;
    }

    return total;
}

int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Sum is: " << miniSubarraySum(arr);

    return 0;
}