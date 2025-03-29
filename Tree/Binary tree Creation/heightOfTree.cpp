#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
 };

 Node* buildTree(Node* &root){


    cout << "Enter the data: "<< endl;
    int data;
    cin >> data;

     root = new Node(data);

     if(root->data == -1) return NULL;

     cout << "Enter the left child of " << root->data << endl;
     root->left = buildTree(root->left);

     cout << "Enter the right child of " << root->data << endl;
     root->right = buildTree(root->right);

     return root;
 }

 int height(Node* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) +1;
    return ans;
 }


int main(){

    Node* root = NULL;
    root = buildTree(root);

    int ans = height(root);
    cout << "The Height of BT is: ";
    cout << ans << endl;

return 0;
}