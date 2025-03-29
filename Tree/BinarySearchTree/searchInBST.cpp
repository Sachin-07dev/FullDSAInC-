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

bool searchBST(node* root, int d){
    
    if(root == nullptr){
        return false;
    }

    if(root->data == d){
        return true;
    }

    if(d > root->data){
        return searchBST(root->right,d);
    }else{
        return searchBST(root->left,d);
    }
}
// void inorder(node* root){
//     if(root){
//         inorder(root->left);
//         cout << root->data << " ";
//         inorder(root->right);
//     }
// }

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
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
     if(searchBST(root,key) == true){
        cout << "The " << key << " is found in the BST" << endl;
     }else{
        cout << "The " << key << " is not found" ;
     }

return 0;
}