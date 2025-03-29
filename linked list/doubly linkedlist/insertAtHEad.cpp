#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // create a constructor to define the new to initialize a linked list object with the existing ones.
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// traversing part of the linkedlist
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 13);
    print(head);

    return 0;
}