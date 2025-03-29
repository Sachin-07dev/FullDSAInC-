#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2; // s1 for push, s2 for pop

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);

    cout << "Front Element: " << myQueue.peek() << endl; // Output: 1
    cout << "Popped Element: " << myQueue.pop() << endl; // Output: 1
    cout << "Is Queue Empty? " << (myQueue.empty() ? "Yes" : "No") << endl; // Output: No

    return 0;
}
