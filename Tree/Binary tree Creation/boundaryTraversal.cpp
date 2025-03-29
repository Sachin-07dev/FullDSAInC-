#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* buildTree() {
    int data;
    cin >> data;
    if (data == -1) return NULL; 

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void traverseLeft(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    ans.push_back(root->data);
    if (root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}


void traverseLeaf(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}


vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    ans.push_back(root->data);

    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    Node* root = buildTree();
    vector<int> ans = boundaryTraversal(root);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
