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

//  Node* reverse(Node* head){
//       Node* temp = head;
//       Node* next = nullptr;
//       Node* prev = nullptr;

//       while(temp != nullptr){
//         next = temp->next; // store the next node at temp
//         temp->next = prev;// link to the prev node
//         prev = temp;// move previous forward
//         temp = next;//move temp forward

//       }
//       return prev;

//  }

//using recursion

Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* remaingList = reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

    return remaingList;
}
void insert(Node* &head, int data){
    Node* newNode = new Node(data);

    if(head == nullptr){
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
        cout << head->data << "->";
        head = head->next;
    }cout << "#" << endl;
}

int main(){

    int N;
    cout << " Emter the number of element in list: ";
    cin >> N;

    Node* head = nullptr; 

    for(int i=0;i<N;i++){
        int data;
        cin >> data;
        insert(head,data);
    }

    printList(head);
    head = reverse(head);
    printList(head);

return 0;
}