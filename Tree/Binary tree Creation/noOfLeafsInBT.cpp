#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }
 };

 Node* buildTree(Node* &root){
     
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    
    if(root->data == -1){
        return NULL;
    }

    cout << "Enter in left side of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the right side of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
 }

 void inorder(Node* root, int &count){

    if(root == nullptr){
        return;
    }

    inorder(root->left, count);
    if(root->left == nullptr && root->right == nullptr) count++;
    inorder(root->right, count);

 }

 int noOfLeafNode(Node* root){
      int count = 0;
      inorder(root,count);

      return count;
   }

int main(){

    Node* root = NULL;
    root = buildTree(root);
    
    int ans = noOfLeafNode(root);
    cout << "Total number of leaf node in the tree are: ";
    cout << ans << endl;

return 0;
}