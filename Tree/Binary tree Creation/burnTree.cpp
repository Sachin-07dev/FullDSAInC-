#include<bits/stdc++.h>
using namespace std;

class Node{
   
    public:
      int data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
      }
};

Node* buildTree() {
    int data;
    cin >> data;

    if (data <= 0) return NULL; // Stop if the first input is 0 or negative

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData, rightData;
        
        
        if (!(cin >> leftData) || leftData <= 0) break;  
        temp->left = new Node(leftData);
        q.push(temp->left);

        
        if (!(cin >> rightData) || rightData <= 0) break;
        temp->right = new Node(rightData);
        q.push(temp->right);
    }

    return root;
}

Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
   
   Node* res= nullptr;

   queue<Node*> q;
   q.push(root);

   nodeToParent[root] = nullptr;

   while(!q.empty()){
    Node* front = q.front();
    q.pop();

    if(front->data == target){
        res = front;
    }

    if(front->left){
        q.push(front->left);
        nodeToParent[front->left] = front;
    }

    if(front->right){
        q.push(front->right);
        nodeToParent[front->right] = front;
    }
   }

   return res;
}

int burnTree(Node* root, map<Node*,Node*> &mpp){

    int ans;
    queue<Node*>q;
    map<Node*, bool> visited;

    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        
        int size = q.size();
        bool flag = false;

        for(int i=0;i<size;i++){
           Node* front = q.front();
           q.pop();

           if(front->left && !visited[front->left]){
            flag = true;
            q.push(front->left);
            visited[front->left] = true;
           }

           if(front->right && !visited[front->right]){
            flag = true;
            q.push(front->right);
            visited[front->right] = true;
           }

           if(mpp[front] && !visited[mpp[front]]){
            flag = true;
            q.push(mpp[front]);
            visited[mpp[front]] = true;
           }
        }

        if(flag == true){
            ans++;
        } 
    }
     return ans;
}
int main(){

    //step-1:find nodeToParent mapping and find targrt
    //step2-use visited map to traverse that the node is burned or not
    
    Node* root = nullptr;
    root = buildTree();
    map<Node*, Node*> nodeToParent;
    int target;
    cin >> target;
    Node* targetNode = createParentMapping(root, target,nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    cout << ans;
    return 0;
}