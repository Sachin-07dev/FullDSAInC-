#include<iostream>
using namespace std;

class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

    void displayQueue(int qn) {
        if (front[qn - 1] == -1) {
            cout << "Queue " << qn << " is empty." << endl;
            return;
        }

        cout << "Elements in Queue " << qn << ": ";
        int index = front[qn - 1];
        while (index != -1) {
            cout << arr[index] << " ";
            index = next[index]; // Move to the next element
        }
        cout << endl;
    }

};

int main() {
    int n, k;
    cout << "Enter total size of the array: ";
    cin >> n;
    cout << "Enter number of queues: ";
    cin >> k;

    kQueue q(n, k);

    int choice;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data, qn;
            cout << "Enter queue number (1 to " << k << "): ";
            cin >> qn;
            if (qn < 1 || qn > k) {
                cout << "Invalid queue number!" << endl;
                continue;
            }
            cout << "Enter data: ";
            cin >> data;
            q.enqueue(data, qn);
        } 
        else if (choice == 2) {
            int qn;
            cout << "Enter queue number (1 to " << k << "): ";
            cin >> qn;
            if (qn < 1 || qn > k) {
                cout << "Invalid queue number!" << endl;
                continue;
            }
            int result = q.dequeue(qn);
            if (result != -1) {
                cout << "Dequeued element: " << result << endl;
            }
        } 
        else if (choice == 3) {
            int qn;
            cout << "Enter queue number (1 to " << k << "): ";
            cin >> qn;
            if (qn < 1 || qn > k) {
                cout << "Invalid queue number!" << endl;
                continue;
            }
            q.displayQueue(qn);
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            cout << "Invalid choice! Please enter again." << endl;
        }
    }

    return 0;
}