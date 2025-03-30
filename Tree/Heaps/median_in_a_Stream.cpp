#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void callMedian(int element, priority_queue<int>&maxHeap, priority_queue<int, vector<int>, greater<int>>&minHeap, int &median){
      
     switch(minHeap.size(), maxHeap.size()){

        case 0:
            if(element > median){
                minHeap.push(element);
                median = minHeap.top();
            }else{
                maxHeap.push(element);
                median = maxHeap.top();
            }
        break;
        
        case 1:
            if(element > median){
                minHeap.push(element);
            }else{
                minHeap.push(maxHeap.top());
                minHeap.pop();
                maxHeap.push(element);
            }
            median = (minHeap.top()+maxHeap.top())/2;
        break;
        
        case -1:
            if(element > median){
                maxHeap.push(minHeap.top());
                maxHeap.pop();
                minHeap.push(element);
            }else{
                maxHeap.push(element);
            }
            median = (minHeap.top()+maxHeap.top())/2;
        break;
     }
}

vector<int> findMedian(vector<int> arr, int n){

    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    for(int i=0;i<n;i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}

int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> result  = findMedian(arr,n);
    cout << "Median: " << result[result.size()-1];

    return 0;
}