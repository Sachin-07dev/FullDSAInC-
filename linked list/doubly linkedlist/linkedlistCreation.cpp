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
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}
  // finding the length of the linkedlist
int getLength(Node *head)
{
    int len = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;

    print(head);
    cout << getLength(head) << endl;

    return 0;
}