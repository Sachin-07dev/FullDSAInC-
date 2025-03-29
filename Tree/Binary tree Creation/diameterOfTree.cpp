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

//  int diameter(Node* root){

//     if(root == NULL){
//         return 0;
//     }

//     int opt1 = diameter(root->left);
//     int opt2 = diameter(root->right);
//     int opt3 = height(root->left) + height(root->right) + 1;

//     int ans = max(opt1, max(opt2, opt3));
//     return ans;
//  }

pair<int, int> diameter(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second+1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second, right.second)+1;

    
        return ans;
    }

int main(){

    Node* root = NULL;
    root = buildTree(root);

    // int ans = diameter(root);
    // cout << "The diameter of the tree is: " << ans << endl;

    cout << "The diameter of the tree is: " << diameter(root).first << endl;

return 0;
}