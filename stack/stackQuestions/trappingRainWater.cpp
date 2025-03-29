#include<bits/stdc++.h>
using namespace std;


// int trapWater(vector<int>& arr){
//     int n = arr.size();

//     int prefix[n];
//     prefix[0] = arr[0];
//     for(int i=1;i<n-1;i++){
//        prefix[i] = max(prefix[i-1], arr[i]);
//     }

//     int suffix[n];
//     suffix[n-1] = arr[n-1];
//     for(int i=n-2;i>=0;i--){
//        suffix[i] = max(suffix[i+1], arr[i]);
//     }

//     int totalTrappedwater = 0;
//     for(int i=0;i<n-1;i++){
//         totalTrappedwater += min(prefix[i],suffix[i])-arr[i];
//     }

//     return totalTrappedwater;
// } this takes O(2n) space that needs to be obtimized

// it can obtimized using the 2 way traversig in which we use left = 0 and right =n-1 for trversing from both starting and ending given array.

int trapWater(vector<int>& arr){
    int n = arr.size();
    int lmax = 0;
    int rmax = 0;
    int totalTrappedwater = 0;
    int left = 0;
    int right = n-1;

    while(left<=right){
            if(arr[left] <= arr[left]){
                if(lmax > arr[left]) totalTrappedwater += lmax - arr[left];
                else  lmax = arr[left];

                left++;
            }else{
                if(rmax > arr[right]) totalTrappedwater += rmax - arr[right];
                else  rmax = arr[right];

                right--; 
            }
        }
        return totalTrappedwater;

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

    int res = trapWater(arr);
    cout << res << endl;

    return 0;
}