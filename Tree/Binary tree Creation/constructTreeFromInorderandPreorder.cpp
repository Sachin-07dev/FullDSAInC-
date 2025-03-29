#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int x){
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
      }
};

void postOrder(Node* root){
    if(root == nullptr){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}
Node* solve(vector<int>& inorder, vector<int>& preorder,int &index, unordered_map<int, int>& mpp,int start, int end)
{
    //base case
    if(start > end || index > preorder.size())
    return nullptr;

    int element = preorder[index++];
    Node* root = new Node(element);

    int pos = mpp[element];
    root->left = solve(inorder,preorder,index,mpp,start,pos-1);
    root->right = solve(inorder,preorder,index,mpp,pos+1,end);

    return root;
}
int main(){
   int n;
   cout << "Enter the size of inorder & preorder vectors: ";
   cin >> n;
   vector<int> preorder(n),inorder(n);

   cout << "Enter preorder elements: ";
   for(int i=0;i<n;i++){
    cin >> preorder[i];
   }

   cout << "Enter inorder elements: ";
   for(int i=0;i<n;i++){
    cin >> inorder[i];
   }

   int preIndex = 0;
   unordered_map<int,int> mpp;
   for(int i=0;i<n;i++){
    mpp[inorder[i]] = i;
   }
   Node* root = solve(inorder,preorder,preIndex,mpp,0,n-1);
   postOrder(root);
   cout << endl;

return 0;
}