#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to create a binary tree
Node* createBTree() {
    int data;
    cout << "Enter node value (-1 for NULL): ";
    cin >> data;

    if (data == -1) return nullptr;

    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = createBTree();
    cout << "Enter right child of " << data << endl;
    root->right = createBTree();

    return root;
}

// Level order traversal
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            //cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// Store BST in in-order traversal
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Convert sorted array to Min-Heap using level order filling
void fillHeap(Node* root, vector<int>& arr, int& index) {
    if (!root) return;

    root->data = arr[index++];
    fillHeap(root->left, arr, index);
    fillHeap(root->right, arr, index);
}

// Convert BST to Min-Heap
void BSTtoMinHeap(Node* root) {
    vector<int> arr;
    inorder(root, arr);  // Step 1: Store BST in sorted order
    int index = 0;
    fillHeap(root, arr, index);  // Step 2: Convert BST to Min-Heap
}

int main() {
    Node* root = nullptr;

    cout << "Create a Binary Search Tree (BST):\n";
    root = createBTree();

    cout << "\nBefore conversion (BST Level Order):" << endl;
    levelOrderTraversal(root);

    BSTtoMinHeap(root);

    cout << "\nAfter conversion (Min-Heap Level Order):" << endl;
    levelOrderTraversal(root);

    return 0;
}
