#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count =0;

    for(int i=s; i<e; i++){
       if(arr[i] == pivot)
       count++;
    }
  // pivot ko right postion per replace kar do 
   int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    // left and right part ko sort kar do 
    int i=s, j=e;
    while(i<pivotIndex && j> pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i<pivotIndex && j> pivotIndex)
          swap(arr[i++], arr[j--]);
    }
}
void quickSort(int arr, int s, int e){
    // base case
    if(s>=e)
     return ;

    // partition karte hain 
    int p = partition(arr, s, e);

    // right side sort karte hain
    quickSort(arr,s, p-1);

    // left side sort karte hain
    quickSort(arr, p+1, e);
}     
int main(){

int arr[5] ={2,7,54,33,88};
int n=5;

quickSort(arr, 0, n-1);

for(int i=0; i<n; i++){
    cout << "Array is sorted" << arr[i] <<" ";
}
cout << endl;
return 0;
}