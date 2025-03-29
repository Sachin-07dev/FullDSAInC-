#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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

Node* preorderToBST(vector<int>& preorder, int &index, int min, int max){

    int data = preorder[index];
    if(index >= preorder.size() || (data < min || data > max)){
         return nullptr;
    }
    Node* temp = new Node(data);
    index++;

    temp->left = preorderToBST(preorder, index, min, data);
    temp->right = preorderToBST(preorder, index, data, max);

    return temp;
}

void preorderTrav(Node* &root){
    if(root){
       cout << root->data << " ";
       preorderTrav(root->left);
       preorderTrav(root->right);
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
      Node* temp = q.front();
      q.pop();

      if(temp == NULL){
          //cout << endl;
          if(!q.empty()){
              q.push(NULL);
          }
      }else{
          cout << temp->data << " ";
          if(temp->left) q.push(temp->left);
       
          if(temp->right) q.push(temp->right);
      }
    }
}  

int main(){


    Node* root = nullptr;
    int index = 0;
    int n;
    cin >> n;
    vector<int> preorder(n);
    cout << "Enter the data in preorder array :";
    for(int i=0;i<n;i++){
        cin >> preorder[i];
    }

    root = preorderToBST(preorder, index, INT_MIN, INT_MAX);
    preorderTrav(root);
    levelOrderTraversal(root);
return 0;
}
