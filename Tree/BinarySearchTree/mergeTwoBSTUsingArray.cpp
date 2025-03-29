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

Node* insert(Node* root, int data){
        
     if(root== nullptr){
        root = new Node(data);
        return root;
     }
     
     if(root->data > data){
        root->left = insert(root->left, data);
     }else{
        root->right = insert(root->right, data);
     }
   
     return root;
}

void inorder(Node* root, vector<int>& vec){
    if(root){
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }
}

vector<int> mergeVectors(vector<int> v1, vector<int> v2){

    int i=0;
    int j=0;
    int k =0;
    vector<int> v(v1.size() + v2.size());
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
           v[k++] = v1[i++];
        }else{
           v[k++] = v2[j++];
        }
    }

    while(i<v1.size()){
        v[k++] = v1[i++];
    }
    while(j<v2.size()){
        v[k++] = v2[j++];
    }

    return v;
}

Node* inorderToBST(vector<int> res, int s , int e){
    if(s>e){
        return nullptr;
    }

    int mid = s + (e-s)/2;
    Node* temp = new Node(res[mid]);

    temp->left = inorderToBST(res, s , mid-1);
    temp->right = inorderToBST(res, mid+1,e);

    return temp;
}

void printInorder(Node* root){
    if(root){
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}
int main(){
   
    Node* root1 = nullptr;
    Node* root2 = nullptr;

    int data1;
    cin >> data1;
    while(data1 > 0){
        root1 = insert(root1,data1);
        cin >> data1;
    }

    int data2;
    cin >> data2;
    while(data2 > 0){
        root2 = insert(root2,data2);
        cin >> data2;
    }

    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2,v2);

    vector<int> res = mergeVectors(v1,v2);

    Node* resultanBST = inorderToBST(res,0,res.size()-1);

   printInorder(resultanBST);

return 0;
}