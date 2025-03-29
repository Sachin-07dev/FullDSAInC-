#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> arr, int i, int n){

    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
  
    if(left <n && arr[largest] < arr[left]){
      largest = left;
    }else if(right <n && arr[largest] < arr[right]){
      largest = right;
    }else{
      return;
    }
  
    if(largest != i){
      swap(arr[largest], arr[i]);
      heapify(arr,largest,n);
    }
  }
vector<int> mergeHeaps(vector<int> arr1, vector<int> arr2){
    for(auto i : arr2){
         arr1.push_back(i);
    }

    for(int i=arr1.size()/2-1;i>=0;i--){
        heapify(arr1, i, arr1.size());
    }

    return arr1;
}

int main(){

    vector<int> arr1, arr2;

    cout << "Enter the element of arr1: ";
    int temp;
    cin >> temp;
    while(temp != -1){
        arr1.push_back(temp);
        cin >> temp;
    }

    cout << "Enter the element of arr2: ";
    cin >> temp;
    while(temp != -1){
        arr2.push_back(temp);
        cin >> temp;
    }

    vector<int> ans = mergeHeaps(arr1,arr2);
    cout << "Merged Heap is: ";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}