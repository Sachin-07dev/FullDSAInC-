#include<iostream>
#include<queue>
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

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);

    return root;
}

Node* buildTree(Node* root){

    int data;
    cout << "Enter the root data for the BST: ";
    cin >> data;
    if(root == nullptr){
       root = new Node(data);
    }
    queue<Node*>q;
    q.push(root);

    while (true) {
        cin >> data;
        if (data == -1) break; // Stop input

        insertBST(root, data); // Insert the value into BST
    }

     return root;
} 

void flattenBST(Node* root, Node* &head){
 
    if(root == nullptr){
        return;
    }
    flattenBST(root->right, head);

    root->right = head;
    if(head != nullptr){
        head->left = root;
    }

    head = root;
    flattenBST(root->left, head);
}

Node* mergeLL(Node* head1, Node* head2){
    Node* head = nullptr;
    Node* tail = nullptr;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(Node* list){
    Node* temp = list;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* ConvertDLLToBST(Node* head, int n){

    if(n<=0 && head == nullptr){
        return nullptr;
    }

    Node* left = ConvertDLLToBST(head,n/2);

    Node* root = head;
    root->left = left;

    head = head->right;
    root->right = ConvertDLLToBST(head, n-n/2-1);

    return root;
}

void bstinorder(Node* root){
    if(root){
        bstinorder(root->left);
        cout << root->data << " ";
        bstinorder(root->right);
    }
}
int main(){

    Node* root1 = nullptr;
    Node* root2 = nullptr;

    root1 = buildTree(root1);
    root2 = buildTree(root2);
// Steps include in merging two tree using linked list

Node* head1 = nullptr;
Node* head2 = nullptr;
// step1:  convert the bst into sorted DLL
flattenBST(root1,head1);
flattenBST(root2,head2);

// step2: merge the Sorted DLL
Node* list = mergeLL(head1, head2);

//step3: convert Sorted DLL to BST
Node* result = ConvertDLLToBST(list, countNode(list));

bstinorder(result);

return 0;
}