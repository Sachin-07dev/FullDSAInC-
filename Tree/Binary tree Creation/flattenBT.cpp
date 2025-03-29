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

Node* buildTree(Node* root){

    int data;
    cin >> data;
    root = new Node(data);

    if(data <= 0) return nullptr;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void flattenToLL(Node* root){

    Node* curr = root;
    while(curr != nullptr){

        if(curr->left){

            Node* pred = curr->left;
            while(pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;    
        }
        curr = curr->right;
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data <<" ";
        inorder(root->right);
    }
}
int main(){

 Node* root = nullptr;

 root = buildTree(root);

 flattenToLL(root);

 inorder(root);

return 0;
}