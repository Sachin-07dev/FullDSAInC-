#include<bits/stdc++.h>
using namespace std;

class MinStack {
  stack < long long > st;
  long long mini;
  public:
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};

int main() {
    MinStack minStack;
    int choice;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Get Top\n";
        cout << "4. Get Min\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            minStack.push(value);
            cout << "Pushed " << value << " into the stack.\n";
        } 
        else if (choice == 2) {
            minStack.pop();
            cout << "Popped from stack.\n";
        } 
        else if (choice == 3) {
            int topValue = minStack.top();
            if (topValue == -1) cout << "Stack is empty.\n";
            else cout << "Top element: " << topValue << endl;
        } 
        else if (choice == 4) {
            int minValue = minStack.getMin();
            if (minValue == -1) cout << "Stack is empty.\n";
            else cout << "Minimum element: " << minValue << endl;
        } 
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
