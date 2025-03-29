#include<iostream>
using namespace std;

  bool isSorted(int arr[], int n){

    // base case
    if(n==0 || n==1)
    return true;

    if(arr[0] > arr[1])
    return false;

     else{
      bool ans = isSorted(arr+1, n-1);
      return ans;
     }
  }

int main(){
  
  int arr[5]= {2,6,4,7,5};
  int n =5;

   bool ans = isSorted(arr, n);

   if(ans){
    cout <<"Array is Sorted" << endl;
   }
   else
   cout << "Array is not sorted" << endl;
return 0;
}