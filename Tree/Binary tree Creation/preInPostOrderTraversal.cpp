#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
     int data;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
     }
};

// TreeNode* buildTree(TreeNode* root){
//    if (root == nullptr) return {};

//    queue<TreeNode*> q;
//    q.push(root);
//    q.push(nullptr); // Marker for end of level
//    vector<vector<int>> ans;
//    vector<int> currLevel;

//    while (!q.empty()) {
    
//        TreeNode* currNode = q.front();
//        q.pop();

//        if (currNode == nullptr) {

//            ans.push_back(currLevel);
//            currLevel.clear();

//            if (q.empty()) break;
//            q.push(nullptr); // Marker for the next level
//        } else {

//            currLevel.push_back(currNode->data);

//            if (currNode->left) q.push(currNode->left);
//            if (currNode->right) q.push(currNode->right);
//        }
//    }

//    return root;
// }

TreeNode* insert(TreeNode* root, int data){

    if(!root)
    return new TreeNode(data);

    // if(data == -1){
    // return NULL;
    // }

    if(data < root->data){
       root-> left = insert(root->left,data);
    }else{
       root -> right = insert(root->right,data);
    }
    return root;
}


void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = NULL;
    int choice, n, value;

    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> value;
                root = insert(root, value);
            }
        } else if (choice == 2) {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        } else if (choice == 3) {
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
        } else if (choice == 4) {
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}