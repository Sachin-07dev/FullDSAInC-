#include<iostream>
using namespace std;
 
class Dequeue{
    int *arr;
    int front;
    int rear;
    int size;


    public:
       Dequeue(int n){
        size = n;
        arr= new int[n];
        front = rear = -1;
       }

    bool pushFront(int x){
        // if it is full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }else if(front == -1){
            front = rear = 0;
        }else if(front == 0 || rear != size-1){
            front = size-1;
        }else{
            front++;
        }

        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        // if it is full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }else if(front == -1){
            front = rear = 0;
        }else if(rear == size -1 && front != 0){
            rear = 0;
        }else{
            rear--;
        }
        arr[rear] = x;
        return true;
    }

    int popFront(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front  = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else{
            front++;
        }

        return ans;
    }

    int popRear(){
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front  = rear = -1;
        }else if(rear == 0){
            rear = size -1;
        }else{
            rear--;
        }

        return ans;
    }

    int getFront(){
        if(isEmpty()){
            return -2;
        }

        return arr[front];
    }
    
    int getRear(){
        if(isEmpty()){
            return -2;
        }

        return arr[rear];
    }
    
    bool isEmpty(){
        if(front == -1){
            return true;
        }

        return false;
    }

    bool isFull(){
       if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
        return true;
       }
       return false;
    }
   
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

};


int main(){
  
   int n;
    cout << "Enter the size of the queue: ";
    cin >> n;

    Dequeue dq(n);

    int choice, value;
    do {
        cout << "\n1. Push Front\n2. Push Rear\n3. Pop Front\n4. Pop Rear\n5. Get Front\n6. Get Rear\n7. Display Queue\n8. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push at front: ";
                cin >> value;
                dq.pushFront(value);
                break;
            case 2:
                cout << "Enter value to push at rear: ";
                cin >> value;
                dq.pushRear(value);
                break;
            case 3:
                cout << "Popped from front: " << dq.popFront() << endl;
                break;
            case 4:
                cout << "Popped from rear: " << dq.popRear() << endl;
                break;
            case 5:
                cout << "Front element: " << dq.getFront() << endl;
                break;
            case 6:
                cout << "Rear element: " << dq.getRear() << endl;
                break;
            case 7:
                dq.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);
  
return 0;
}