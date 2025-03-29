#include<bits/stdc++.h>
using namespace std;

class Node{
   
    public: 
      int data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
      }
};

Node* buildTree(Node* root){
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

pair<int, int> solve(Node*  root){

    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;


}

int main(){
    
    int t;
    cin >> t;

    while(t--){

    Node* root = buildTree(root);
    pair<int,int> res = solve(root);

    cout <<  max(res.first,res.second) << endl    ;

    }
    return 0;
}