#include<iostream>
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

 Node* buildTree(Node* root){

    cout << "Enter the data: "<<endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(root->data == -1) return NULL;

    cout << "Enter data in left child of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data in right child of " << root->data << endl;
    root->left = buildTree(root->left);

    return root;
 }
  
 int height(Node* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) +1;
    return ans;
 }

 pair<bool,int> isBalancedFast(Node* root){

    if(root == NULL){
        pair<int, int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second-right.second)<=1;
    
    pair<bool, int> ans;

    if(leftAns && rightAns && diff){
       ans.first = true;
    } 

    ans.second = max(left.second,right.second)+1;

    return ans;
 }

//   bool isBalanced(Node* root){   

//     return isBalancedFast(root).first;
//     // if(root == NULL){
//     //     return true;
//     // }

//     // bool left = isBalanced(root->left);
//     // bool right = isBalanced(root->right);

//     // bool diff = abs(height(root->left)- height(root->right))<=1;
    
//     // if(left && right && diff){
//     //     return true;
//     // }else{
//     //     return false;
//     // }
//  }

int main(){ 


    Node* root = NULL;
    root = buildTree(root);
 
    if(isBalancedFast(root).first){
        cout << "BT is Balanced Tree" << endl;
    }else{
        cout << "BT is not Balanced Tree" << endl;
    }

return 0;
}