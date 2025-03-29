#include<iostream>
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

void insertAtHead(Node* &head, int data){

    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        return;
    }
   newNode->next = head;
   head = newNode;
}

void insertAtTail(Node* &head, int data){

    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    temp = newNode;
}

void printList(Node* head){
    
    while(head != nullptr){
        cout << head->data << "=>";
        head = head->next;
    }cout << "NULL" << endl;
}
int main(){
    
    int N;
    cout << "Enter the size of list: ";
    cin >> N;

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    for(int i=0;i<N;i++){
        int data;
        cin >> data;
        insertAtHead(head1,data);
    }

    for(int i=0;i<N;i++){
        int data;
        cin >> data;
        insertAtTail(head2,data);
    }
    printList(head1);
    printList(head2);
    return 0;
}