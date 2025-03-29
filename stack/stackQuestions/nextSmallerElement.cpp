#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> num){

    int n = num.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= num[i]){
            st.pop();
        }

        ans [i] = st.empty() ? -1 : st.top();

    st.push(num[i]);    
    }
       
    return ans;   
  
 }

int main(){
    int n;
    cout <<"Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout <<"Enter array elements: "; 
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
     
    vector<int> res = nextSmallerElement(arr);
    for(int i =0;i<n;i++){
        cout << res[i] <<" ";
    }

    return 0;
}