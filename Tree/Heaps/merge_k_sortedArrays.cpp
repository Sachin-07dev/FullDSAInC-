#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    
    public:
       int data;
       int row;
       int col;

       Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
       }
};

class compare{
     public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
vector<int> mergeSortedArrays(vector<vector<int>> KArrays, int k ){
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(int row = 0;row < k;row++){
        Node* temp = new Node(KArrays[row][0],row,0);
        minHeap.push(temp);
    }  
    vector<int> ans;
    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col+1 < KArrays[row].size()){
            Node* next = new Node(KArrays[row][col+1],row,col+1);
            minHeap.push(next);
        }
        delete temp;
    }
    return ans;
}

int main(){

    vector<vector<int>> KArrays;
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    for(int i=0;i<k;i++){
        vector<int> arr;
        cout << "Enter the element of " << i+1 << " array: ";
        int data;
        cin >> data;
        while(data != -1){
            arr.push_back(data);
            cin >> data;
        }
        KArrays.push_back(arr);
    }

    vector<int> mergedArray = mergeSortedArrays(KArrays, k);

    for(auto it: mergedArray){
        cout << it << " ";
    }cout << endl;
    
    return 0;
}