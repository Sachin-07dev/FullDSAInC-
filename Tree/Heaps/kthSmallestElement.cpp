#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthSmallest(vector<int>arr, int k){
      int n = arr.size();

      priority_queue<int> pq;

      for(int i=0;i<k;i++){
          pq.push(arr[i]);
      }

      for(int i=k;i<n;i++){
          if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
          }
      }
      return pq.top();
}

int main(){

    vector<int> arr;

    cout << "Enter the Element of the array : ";
    int data;
    cin >> data;
    while(data != -1){
        arr.push_back(data);
        cin >> data;
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int ans = kthSmallest(arr, k);
    cout << k << "thSmallest Element of Array is: " << ans;

    return 0;

}