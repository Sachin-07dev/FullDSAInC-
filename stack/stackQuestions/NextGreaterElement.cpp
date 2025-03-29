// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element 
//of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();

            }
            if(st.empty()) mpp[nums2[i]] = -1;
            else{
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }
        vector<int> ans;

        for(int num:nums1){
            ans.push_back(mpp[num]);
        }
        return ans;
    }

int main(){
    
    int n1,n2;
    cout << "Enter the sixe of both arrays num1 & num2: ";
    cin >> n1 >> n2;

    vector<int> num1(n1);
    vector<int> num2(n2);

    cout << "Enter the element of num1: ";
    for(int i=0;i<n1;i++){
        cin >> num1[i];
    }

    cout << "Enter the element of num2: ";
    for(int i=0;i<n2;i++){
        cin >> num2[i];
    }
    
    vector<int> result =  nextGreaterElement( num1, num2);

    for(int i=0;i<n1;i++){
        cout << result[i] <<" ";
    }


    return 0;
}