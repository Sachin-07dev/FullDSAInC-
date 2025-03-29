#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtHead(Node* &head, int d){
    // create a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt =1;

    while(cnt < position -1){
        temp =temp->next;
        cnt++;
    }
     
     if(temp ->next == NULL){
     insertAtTail(tail, d);
     return;
     }
    // creating a node for Data
    Node* nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteNode(int position, Node* head){
    //deleting the first node
    if(position ==1){
      Node* temp = head;
      head = head->next;
     // memory feee start node
     temp ->next = NULL;
     delete temp;

    }
    else{
    //deleting the middle or the last node
    Node* curr = head;
    Node* prev = NULL;

    int cnt =1;
    while(cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    
    prev->next = curr->next;
    curr->next =NULL;
    delete curr;

    }
}
void print(Node* &head){
    Node*temp = head;
    while (temp!=NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;

    }
    
    cout<<endl;
}

int main(){

// create n new node
Node* node1 = new Node(10);

Node* head = node1;
Node* tail =node1;
print(head);

insertAtHead(head,8);
print(head);
insertAtHead(head,6);
print(head);
insertAtHead(head,4);
print(head);

insertAtTail(tail,16);
print(head);
insertAtTail(tail,18);
print(head);
insertAtTail(tail,19);
print(head);

insertAtPosition(tail,head,3,7);
print(head);

cout <<"head" << head->data << endl;
cout <<"tail" << tail->data << endl;
 
deleteNode(1,head);
print(head);

return 0;
}