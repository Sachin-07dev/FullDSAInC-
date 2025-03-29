#include<bits/stdc++.h>
using namespace std;

class Node{
   
    public:
       int data;
       Node* left;
       Node* right;

       Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
       }
};

Node* insert(Node* root, int data){

    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }

    return root;
}

pair<int, int> predSucc(Node* root, int key){

    Node* keyNode = root;
    int pred = -1;
    int succ = -1;
    while(keyNode->data != key){
        if(keyNode->data > key){
            succ = keyNode->data;
            keyNode = keyNode->left;
        }else{
            pred = keyNode->data;
            keyNode = keyNode->right;
        }
    }

    //predecessor
    Node* leftTree = keyNode->left;
    while(leftTree != nullptr){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    //successor
    Node* rightTree = keyNode->right;
    while(rightTree != nullptr){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
   pair<int, int> res;
   res.first = pred;
   res.second = succ;

   return res;
}

int main(){

   Node* root = nullptr;

   int data;
   cin >> data;
   while(data > 0){
       root = insert(root,data);
       cin >> data;
   }

   int key;
   cout << "Enter the key of which predecessor and successor is to be found:  ";
   cin >> key;

   pair<int,int> ans = predSucc(root,key);

   cout << "Predecessor of " << key << " is : " << ans.first << endl;
   cout << "successor of " << key << " is : " << ans.second << endl;


return 0;
}