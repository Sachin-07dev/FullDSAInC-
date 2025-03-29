#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
   public:
     int data;
     Node* next;

     Node(int data){
        this->data = data;
        this->next = nullptr;
     }
};

class compare{
    public:
      bool operator()(Node* a, Node* b){
        return a->data > b->data;
      }
};

void insert(Node* &head, Node* &tail,int data){
    Node* temp = new Node(data);
    if(head == nullptr){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

Node* mergeKLists(vector<Node*> KLists, int k){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    if(k == 0) return nullptr;
    // insering first node of all LL to the minHeap
    for(int i=0;i<k;i++){
        if(KLists[i] != nullptr){
            minHeap.push(KLists[i]);
        }
    }
    // now create a Ll HEAD AND TAIL on which next nodes should be added and return  
    Node* head = nullptr;
    Node* tail = nullptr;
    
    //comparing all next nodes
    while(minHeap.size() > 0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != nullptr){
            minHeap.push(top->next);
        }
        if(head == nullptr){
            head = tail = top;
        }else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
int main(){
    
    vector<Node*> KLists;
    
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    for(int i=0;i<k;i++){

        Node* head = nullptr;
        Node* tail = nullptr;

        cout << "Enter the values of List(-1 to stop): ";
        int val;
        cin >> val;
        while(val != -1){
            insert(head,tail,val);
            cin >> val;
        }

        KLists.push_back(head);
    }
    
    Node* list = mergeKLists(KLists, k);

    Node* temp = list;
    cout << "Merged List: ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << endl;

    return 0;
}