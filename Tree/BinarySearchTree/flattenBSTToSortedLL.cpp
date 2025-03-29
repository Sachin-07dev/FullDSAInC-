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

void inorder(Node* root, vector<Node*> &ans){
    if(root){

        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
}
void flattenBstToLL(Node* root){

    if(root == nullptr){
        return;
    }

    vector<Node* >ans;
    inorder(root, ans);

    for(int i=0;i<ans.size()-1;i++){
        ans[i]->left = nullptr;
        ans[i]->right = ans[i+1];
    }
    
    ans[ans.size()-1]->left = nullptr;
    ans[ans.size()-1]->right = nullptr;

    root = ans[0];
}

void printList(Node* root){
    Node* temp = root;
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << "NULL" << endl;
}

int main(){

    Node* root= nullptr;

    int data;
    cout << "Enter data in BST: ";
    cin >> data;
    while(data > 0){
        root = buildTree(root,data);
        cin >> data;
    }

    flattenBstToLL(root);
    printList(root);
return 0;
}