#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


void dfs(Node* root, int hd, int &mn, unordered_map<int, vector<int>> &mp) {
    if (root == nullptr) 
        return;
    
    mp[hd].push_back(root->data);
    mn = min(mn, hd);
    
    dfs(root->left, hd - 1, mn, mp);  
    dfs(root->right, hd + 1, mn, mp);
}

vector<vector<int>> verticalOrder(Node *root) {
    
    unordered_map<int, vector<int>> mp;
    
    int mn = 0; 
    dfs(root, 0, mn, mp);
    
    vector<vector<int>> res;
    int hd = mn;

    while(mp.find(hd) != mp.end()) {
        res.push_back(mp[hd]);
        hd++;
    }
  
    return res;
}

// Function to take user input and construct the binary tree
Node* buildTree(Node* &root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);
  
    if(data == -1){
        return NULL;
    }

    cout << "Insert in the left of " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Insert in the right of " << root->data << endl;
    root->right = buildTree(root->right);
    
    return root;
}

int main() {
    Node* root = buildTree(root);
    
    vector<vector<int>> res = verticalOrder(root);
    
    for(vector<int> temp: res) {
        for (int val: temp) 
            cout << val << " ";
    }
    
    return 0;
}
