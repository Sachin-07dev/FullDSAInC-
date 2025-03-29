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

int minVal(node* root){

    if(root == nullptr){
        return -1;
    }
    node* temp = root;
    while(temp->left){
        temp = temp->left;
    }

    return temp->data;
}

 node* deleteNode(node* root, int data){
    
    if(root == nullptr){
        return root;
    }

    if(root->data == data){
        // 0 children
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // 1 children
         if(root->left != nullptr && root->right == nullptr){
             node* temp = root->left;
             delete root;
             return temp;
         }

         if(root->left == nullptr && root->right != nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if(root->left != nullptr && root->right != nullptr){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->data < data){
        root-> right = deleteNode(root->right, data);
        return root;
    }else{
        root->left = deleteNode(root->left,data);
        return root;
    }
 }

int main(){

    node* root = NULL;

    
    cout << "Enter the data in BST: ";
    int data;
    cin >> data;

    while(data > 0){
        root = CreateTree(root,data);
        cin >> data;
    }
    inorder(root);
   
    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    root = deleteNode(root,key);
    inorder(root);
 
return 0;
}