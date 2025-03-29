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

Node* buildTree(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data > data ){
        root->left = buildTree( root->left , data);
    }else{
        root->right = buildTree(root->right, data);
    }

   return root;
}

Node* searchInBST(Node* root, int data){

    if(root == nullptr){
        return nullptr;
    }

    if(root->data == data){
        return root;
    }

    if(data > root->data){
        return searchInBST(root->right,data);
    }else{
        return searchInBST(root->left,data);
    }

    return root;
}

Node* lcaInBST(Node* root, Node* p, Node* q){

    while(root){

        if(root->data < p->data && root->data < q->data){
            root = root->right;
        }else if(root->data > p->data && root->data > q->data){
            root = root->left;
        }else{
            return root;
        }
    }
    return nullptr;
}

int main(){


    Node* root = nullptr;
    int d1,d2;

    int data;
    cout << "Enter data in BST: ";
    cin >> data;
    while(data >= 0){
        root = buildTree(root,data);
        cin >> data;
    }
    cout << "Enter the nodes whose lca is to be found: ";
    cin >> d1 >> d2;
    Node* p = searchInBST(root, d1);
    Node* q = searchInBST(root, d2);

    Node* lcaNode = lcaInBST(root, p ,q);
    
    cout << "The LCA of the " << p->data <<" and " << q->data << " is: ";
    cout << lcaNode->data << endl;

    return 0;
}