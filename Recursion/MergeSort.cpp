#include<iostream>
using namespace std;

void merge(int *arr, int s ,int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

     int *first = new int[len1];
     int *second = new int[len2];

     // copy values
     int mainArrayindex =s;
     for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayindex++];
     }
     mainArrayindex = mid+1;
     for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayindex++];
     }

     // Now merge two sorted Arrays
      int index1 =0;
      int index2= 0;
      mainArrayindex =s;

      while( index1 < len1 && index2 < len2){
        if(first[index1] < second[index1]){
            arr[mainArrayindex++] = first[index1++];
        }
        else{
            arr[mainArrayindex++] = second[index2++];
        }
    } 
    while(index1 < len1 ){
       arr[mainArrayindex++] = first[index1++]; 
    }

    while (index2 < len2){
        arr[mainArrayindex++] = second[index2++];
    }
}  

void mergeSort(int *arr, int s, int e){
    // base case
    if(s>=e){
        return ;
    }
    int mid = s+(e-s)/2;

    // sort the new left array
    mergeSort(arr, s, mid);

    // sort the new right array
    mergeSort(arr, mid+1, e);

    // now merge these new Arrays
    merge(arr,s,e); 
}

int main(){
    int arr[5] ={4,3,5,6,66};
    int n =5;
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
return 0;
}