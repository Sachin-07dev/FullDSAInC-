#include<iostream>
#include<climits>
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

class Info{
    
    public:
      int maxi;
      int mini;
      bool isBST;
      int size;

      Info(){
        this->maxi = INT_MIN;
        this->mini = INT_MAX;
        this->isBST = true;
        this->size = 0;
      }
};

Node* buildBinaryTree(Node* root){

    cout << "Enter the data: "<<endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(root->data == -1) return NULL;

    cout << "Enter data in left child of " << root->data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter data in right child of " << root->data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

Info* solve(Node* root, int &ans){
 
    if(root == nullptr){
        Info* temp = new Info();
        return temp;
    }

    Info* left = solve(root->left,ans);
    Info* right = solve(root->right, ans);
    
    Info* currNode = new Info();

    currNode->size = left->size + right->size + 1;
    currNode->maxi = max(root->data, right->maxi);
    currNode->mini = max(root->data,left->mini);

    if(left->isBST && right->isBST && (root->data > left->maxi && root->data < right->mini)){
        currNode->isBST = true;
    }else{
        currNode->isBST = false;
    }

    if(currNode->isBST){
        ans = max(ans, currNode->size);
    }

    return currNode;

}
int main(){
   
    Node* root = nullptr;

    root = buildBinaryTree(root);

    int ans = INT_MIN;

    Info* res = solve(root, ans);

    cout << "Max BST is: " << ans;

return 0;
}