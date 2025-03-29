#include<bits/stdc++.h>
using namespace std;

vector<int> findnge(vector<int> arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
     while(!st.empty() && arr[st.top()] <= arr[i]){
         st.pop();
     }

    nge[i] = (st.empty())?n:st.top();
    st.push(i);
    }

    return nge;
 }

 vector<int> findpge(vector<int> arr){
    int n = arr.size();
    vector<int> pge(n);
    stack<int>st;

    for(int i=0;i<n;i++){
     while(!st.empty() && arr[st.top()] < arr[i]){
         st.pop();
     }

    pge[i] = (st.empty())?-1:st.top();
    st.push(i);
    }

    return pge;
 }

int maxSubarraySum(vector<int> arr) {
    int n = arr.size();
    int total = 0;
    int mod = (int)(1e9+7);

    vector<int> nse = findnge(arr);
    vector<int> npe = findpge(arr);

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

    cout << "Sum is: " << maxSubarraySum(arr);

    return 0;
}