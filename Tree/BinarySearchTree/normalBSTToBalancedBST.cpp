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

void inorder(Node* root, vector<int> &ans){
    if(root){

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
}
void levelOrderTraversal(Node* root) {
    if (!root) return;  // Edge case handling

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl; // New line for each level
    }
}


Node* isBalancedBST(vector<int> &ans, int s, int e) {
    if(s > e){
        return nullptr;
    }

    int mid = s + (e-s)/2;

    Node* temp = new Node(ans[mid]);

    temp->left = isBalancedBST(ans,s,mid-1);
    temp->right = isBalancedBST(ans,mid+1, e);

    return temp;
}

Node* normalstToBalanceBst(Node* root){

    if(root == nullptr){
        return nullptr;
    }

    vector<int> ans;
    inorder(root, ans);

    Node* newBst = isBalancedBST(ans, 0, ans.size()-1);
    return newBst; 

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

    if (root == nullptr) {
        cout << "Empty BST. No balanced tree to display.\n";
        return 0;
    }
   
    Node* newRoot = normalstToBalanceBst(root);
    cout << "Level order traversal of balanced BST is:" << endl;
    levelOrderTraversal(newRoot);
return 0;
}