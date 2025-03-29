#include<iostream>
using namespace std;

bool linearSearch( int arr[], int size, int k){
   
   // base case
   if(size == 0)
    return false;

    if(arr[0] == k)
    return true;

    bool remainingPart = linearSearch(arr+1, size-1, k);
    return remainingPart;
}
int main(){

    int arr[] = {1,4,5,6,6,3};
    int size =5;
    int key =5;

    bool ans = linearSearch(arr, size, key);

    if(ans){
        cout << "present" << endl;
    }
    else{
        cout << "Absent" << endl;
    }

return 0;
}