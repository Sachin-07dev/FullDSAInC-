#include<iostream>
using namespace std;

void print( int arr[], int s , int e){

    for(int i=s; i<=e; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool binearySearch( int arr[], int s, int e, int k){

    print(arr,s,e);
     
     int mid = s + (e-s)/2;
     cout << " arr mid value is " << arr[mid] << endl;
    //  keyt element  is found
    if(arr[mid] == k)
       return true;

    //element is not found
    if(s>e)
      return false;

    if( arr[mid] > k){
        return binearySearch( arr, mid+1,e,k);
    }
    else{
        return binearySearch( arr, s,mid-1,k);
    }      
}
int main(){

    int arr[] = {1,4,5,6,6,3};
    int size =5;
    int key =5;

    cout << " element is found" << binearySearch(arr, 0,5,key) << endl;

return 0;
}