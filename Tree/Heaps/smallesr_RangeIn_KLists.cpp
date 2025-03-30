#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class Node{
    public:
       int data;
       int row;
       int col;

       Node(int data, int row, int col){
            this->data = data;
            this->col = col;
            this->row = row;
       }
};

class compare{
    public:
      bool operator()(Node* a, Node* b){
        return a->data > b->data;
      }
};
int smallestRange(vector<vector<int>> KArrays, int K, int n){

    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // creating a minHeap for starting element of each list and tracking mini/maxi of each list
    for(int row=0;row<K;row++){
        int element = KArrays[row][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, row, 0));
    }

    int start = mini;
    int end = maxi;

    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

        if(temp->col < n){
            maxi = max(maxi, KArrays[temp->row][temp->col+1]);
            minHeap.push(new Node(KArrays[temp->row][temp->col+1], temp->row,temp->col+1));
        }else{
            break;
        }
    }
    return (end-start+1);
}
int main(){
   
    vector<vector<int>> KArrays;
    int N,K;

    
    cout << "Enter the value of k: ";
    cin >> K;
    
    cout << "Enter the size of array: ";
    cin >> N;

    for(int i=0;i<K;i++){
        vector<int> curr(N);

        cout << "Enter the element of the Arrays: ";
        
        for(int j=0;j<N;j++){
            cin >> curr[j];
        }

        KArrays.push_back(curr);
    }

    int range = smallestRange(KArrays, K, N);
    cout << "Smallest range in the given sorted lists : " << range << endl;
    
    return 0;
}