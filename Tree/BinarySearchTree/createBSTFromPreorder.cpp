#include<iostream>
#include<vector>
using namespace std;
class Node{

    public:
      int data;
      Node* left;
      Node* right;


      Node(int x){
        data = x;
        left = right = nullptr;
      }
};

Node* insertIntoBSt(Node* &root, int data){
      
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertIntoBSt(root->left,data);
    }else{
        root->right = insertIntoBSt(root->right, data);
    }
    return root;
}

void printInorder(Node* root){
    if(root){
        printInorder(root->left);
        cout << root->data <<" ";
        printInorder(root->right);
    }
}
int main(){

    int n;
    cin >> n;
    vector<int> preorder(n);

    for(int i=0;i<n;i++){
        cin >> preorder[i];
    }

    Node* root = nullptr;

    for(int i=0;i<n;i++){
        root = insertIntoBSt(root,preorder[i]);
    }

    printInorder(root);

return 0;
}