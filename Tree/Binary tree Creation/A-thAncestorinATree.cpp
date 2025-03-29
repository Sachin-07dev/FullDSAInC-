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

Node* solve(Node* root, int &k, int node){
    if(root == NULL) return NULL;
    if(root->data == node) return root;

    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MIN;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            k = INT_MIN;
            return root;
        }
        return rightAns;
    }
    return nullptr;
}
int main(){
    
    int t;
    cin >> t;

    while(t--){
    int k, node;
    cin >> k >> node;

    Node* root = buildTree(root);
    Node* res = solve(root, k, node);

    if(res == NULL || res->data == node){
        cout << -1;
    }else{
        cout << res->data;
    }

    }
    return 0;
}