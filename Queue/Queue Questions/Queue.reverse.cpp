#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue {
private:
    queue<int> q; 
public:
 
    void enqueue(int value) {
        q.push(value);
    }

    void dequeue() {
        if (!q.empty()) {
            cout << "Dequeued: " << q.front() << endl;
            q.pop();
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    void reverseQueue() {
        stack<int> s;

        // Step 1: Move all elements to stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Move elements back to queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }

    void display() {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        queue<int> temp = q; 
        cout << "Queue elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
    int n, value;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        myQueue.enqueue(value);
    }

    cout << "\nOriginal Queue: ";
    myQueue.display();

    myQueue.reverseQueue();

    cout << "Reversed Queue: ";
    myQueue.display();

    return 0;
}
