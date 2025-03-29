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
        left = nullptr;
        right = nullptr;
       }
};

void printinorder(Node* root){
  if(root){
    printinorder(root->left);
    cout << root->data <<"->";
    printinorder(root->right);
  }
}
Node* buildTree(Node* root){
     
    int data;
    cin >> data;
    root = new Node(data);

    if(data <= 0){
        return nullptr;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

vector<int> morrisInorder(Node* root){

    Node* curr = root;
    vector<int>ans;

    while(curr != nullptr){
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* prev = curr->left;
            while(prev->right != nullptr && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main(){
     
   Node* root = nullptr;

   root = buildTree(root);
   printinorder(root);
   cout << endl;
   vector<int> res = morrisInorder(root);

   for(int i=0;i<res.size();i++){
      cout << res[i] << " ";
   }cout << endl;

return 0;
}