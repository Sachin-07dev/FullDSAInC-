#include<bits/stdc++.h>
using namespace std;

class Queue{
      int* arr;
      int front;
      int rear;
      int size;

      public:
        Queue(int n){
            size = n;
            arr = new int[size];
            front = 0;
            rear = 0;
        }


        bool isEmpty(){
            if(front == rear){
                return true;
            }
        }

        void enqueue(int val){
            if(rear == size){
                cout << " Queue is full" << endl;
            }else{
                arr[rear] = val;
                rear++;
            }
        }

        int dequeue(){

            //check if the Queue is empty
            if(front == rear){
                return -1;
            }else{
                int ans = arr[front];
                arr[front] = -1;
                front++;
                if(front == rear){
                    front =0;
                    rear = 0;
                }
                return ans;
            }
        }


    int FindFront(){
            if(front == rear){
                return -1;
            }
            return arr[front];
        }
};
using namespace std;

int main(){
     
    Queue *q = new Queue(5);
    

    q->enqueue(12);
    q->enqueue(15);
    q->enqueue(18);
    q->enqueue(21);

    cout << "THe front is:"<< q->FindFront() << endl;

    cout << "\nDequeueing elements:" << endl;
    cout << "Dequeued element: " << q->dequeue() << endl;
    cout << "Dequeued element: " << q->dequeue() << endl;

    cout << "\nAfter Dequeueing:" << endl;

    cout << "Front element: " << q->FindFront() << endl;
    return 0;
}