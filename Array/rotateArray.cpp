#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    vector<int>arr;
    int sum=0,carry=0,r;
    int i=n-1,j=m-1;
    while(i>=0 && j>=0){
        int v1=a[i];
        int v2=b[j];
        sum=a[i]+b[j]+carry;
        carry=sum/10;
        r=sum%10;
        arr.push_back(r);
        j--,i--;
    
    }
    while(i>=0){
        sum=carry+a[i];
        carry=sum/10;
        r=sum%10;
        arr.push_back(r);
        i--;
        
    }
    while(j>=0){
        sum=carry+b[j];
        carry=sum/10;
        r=sum%10;
        arr.push_back(r);
        j--;
        
    }
    if(carry!=0){
            arr.push_back(carry);
        }
    reverse(arr.begin(),arr.end());
    return arr;
       
}