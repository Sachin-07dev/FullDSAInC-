#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    
    public:
      int data;
      Node* left;
      Node* right;


      Node(int x){
        data = x;
        left = right = nullptr;
      }
}; 

Node* buildTree(Node* root){
     
  int rootData;
  cout << "Enter the root data: ";
  cin >> rootData;

  if(rootData == -1) {
    root = nullptr;
    return root;
  }

  root = new Node(rootData);

  queue<Node*>q;
  q.push(root);

  while(!q.empty()){
      Node* front = q.front();
      q.pop();

      int leftData , rightData;
      cout << "Enter the left child of " << front->data << endl;
      cin >> leftData;
      if(leftData != -1){
        front->left = new Node(leftData);
        q.push(front->left);
      }

      cout << "Enter the right Child of " << front->data << endl;
      cin >> rightData;
      if(rightData != -1){
        front->right = new Node(rightData);
        q.push(front->right);
      }
  }

  return root;

}

int countNode(Node* root){
  if(root == nullptr) return 0;

  int left = countNode(root->left);
  int right = countNode(root->right);

  return left + right + 1;
}

bool isCBT(Node* root, int i, int nodeCnt){
  if(root == nullptr){
    return true;
  }

  if( i>= nodeCnt ){
    return false;
  }else{
      return isCBT(root->left, 2*i+1, nodeCnt) && isCBT(root->right, 2*i+2, nodeCnt);
  }
}

bool isMaxHeap(Node* root){

  //base case - if leaf node
  if(root->left == nullptr && root->right == nullptr) return true;

  if(root->right == nullptr){
    return root->data > root->left->data;
  }else{
    return (isMaxHeap(root->left) && isMaxHeap(root->right)) 
    && root->data > root->left->data && root->data > root->right->data;
  }

}

bool isMinHeap(Node* root){

  //base case - if leaf node
  if(root->left == nullptr && root->right == nullptr) return true;

  if(root->right == nullptr){
    return root->data < root->left->data;
  }else{
    return (isMinHeap(root->left) && isMinHeap(root->right)) 
    && root->data < root->left->data && root->data < root->right->data;
  }

}
bool checkMaxHeap(Node* root){
  return isCBT(root, 0, countNode(root)) && isMaxHeap(root);
}

bool checkMinHeap(Node* root){
  return isCBT(root, 0, countNode(root)) && isMinHeap(root);
}
int main(){

    Node* root = nullptr;

    root = buildTree(root);

    bool isMaxHeap = checkMaxHeap(root);
    bool isMinHeap = checkMinHeap(root);

    if(isMaxHeap){
       cout << "Given Binary Tree follows maxHeap Order.";
    }else if(isMinHeap){
       cout << "Given Binary Tree follow MinHeap Order."; 
    }else{
      cout << " Given Binary Tree doesn't folloe Heap Orders.";
    }

    return 0;
}