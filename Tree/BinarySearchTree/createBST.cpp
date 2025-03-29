#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }
 };

 node* CreateTree(node* root, int data){

    if(root == nullptr){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = CreateTree(root->right, data);
    }else{
        root->left = CreateTree(root->left, data);
    }
    return root;
}
void inorder(node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){

    node* root = NULL;

    // create A tree
    cout << "Enter the data in BST: ";
    int data;
    cin >> data;

    while(data > 0){
        root = CreateTree(root,data);
        cin >> data;
    }

    inorder(root);

    //searchBST(root);

return 0;
}