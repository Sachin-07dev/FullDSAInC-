#include<bits/stdc++.h>
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

node* CreateTree(node* root){
    cout << " Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
    return NULL;
    }

    cout << " Enter the data for left child node " << endl;
    root-> left = CreateTree(root->left);
    cout << " Enter tha data for right child node" 
    << endl;
    root -> right = CreateTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
      queue<node*> q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
      }


    //if the return type of function levelOrderTraversal is of vector<vector<int>> the the solution is must be as follows;
    //   if (root == nullptr) return {};

    //   queue<TreeNode*> q;
    //   q.push(root);
    //   q.push(nullptr); // Marker for end of level
    //   vector<vector<int>> ans;
    //   vector<int> currLevel;
  
    //   while (!q.empty()) {
    //       TreeNode* currNode = q.front();
    //       q.pop();
  
    //       if (currNode == nullptr) {
    //           ans.push_back(currLevel);
    //           currLevel.clear();
    //           if (q.empty()) break;
    //           q.push(nullptr); // Marker for the next level
    //       } else {
    //           currLevel.push_back(currNode->val);
    //           if (currNode->left) q.push(currNode->left);
    //           if (currNode->right) q.push(currNode->right);
    //       }
    //   }
  
    //   return ans;
}



int main(){
    node* root = NULL;

    // create A tree
    root = CreateTree(root);
    levelOrderTraversal(root);
  
    return 0;
}