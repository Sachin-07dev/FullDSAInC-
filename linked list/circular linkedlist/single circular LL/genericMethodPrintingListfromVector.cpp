#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int key){
      this->key = key;
      this->next = nullptr;
    }
};

// Function to create a new node
Node* newNode(int key, Node* next = nullptr) {
    Node* node = new Node(key);
    node->next = next;
    return node;
}

// Function to create a circular linked list
Node* createCircularList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = newNode(arr[0]);
    Node* last = head;

    for (int i = 1; i < arr.size(); i++) {
        last->next = newNode(arr[i]);
        last = last->next;
    }

    last->next = head; // Making it circular
    return head;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->key << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "#" << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createCircularList(arr);

    cout << "Circular Linked List: ";
    printList(head);

    return 0;
}
