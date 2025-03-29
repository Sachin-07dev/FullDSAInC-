#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to move the last element to the front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack myStack;
    int choice, value;

    cout << "Stack operations using a single queue\n";
    cout << "1. Push\n2. Pop\n3. Top\n4. Check if empty\n5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                cout << "Popped: " << myStack.pop() << endl;
                break;
            case 3:
                cout << "Top Element: " << myStack.top() << endl;
                break;
            case 4:
                cout << "Is Stack Empty? " << (myStack.empty() ? "Yes" : "No") << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
