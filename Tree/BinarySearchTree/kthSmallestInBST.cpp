#include<bits/stdc++.h>
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

Node* insert(Node* root, int data){
  
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data > data ){
        root->left = insert( root->left , data);
    }else{
        root->right = insert(root->right, data);
    }

   return root;
}

int kthSmallest(Node* root, int &index, int k){

    if(root == nullptr){
        return -1;
    }

    int left = kthSmallest(root->left,index, k);

    if(left != -1){
        return left;
    }

    index++;
    if(index == k){
        return root->data;
    }
    return kthSmallest(root->right , index, k);
}

int main(){
    
   Node* root = nullptr;

   int data;
   cout << "Enter the data in BST: ";
   cin >> data;
    while(data > 0){
        root = insert(root, data);
        cin >> data;
    }

    int k;
    cout << "ENter the k:";
    cin >> k;

    int index = 0;

    int ans = kthSmallest(root, index, k);
    cout << "kthSmallest element in BST is: " << ans << endl;
    return 0;
}