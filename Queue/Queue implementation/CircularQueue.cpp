#include<iostream>
using namespace std;

class Queue{

    int *arr;
    int front;
    int rear;
    int size;


    public:
       Queue(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;
       }

    bool enqueue(int val){
        // check if the queue id full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }else if(front == -1){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = val;
        return true;
    }   

    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] =-1;
        if(front == rear){
            front = rear = -1;
        }else if(front == size-1){
            front =0;
        }else{
            front++;
        }
        return ans;
    }

    bool isEmpty(){
        if(front == -1){
            cout << "Queue is Empty"<< endl;
            return false;
        }else{
            return true;
        }    
    }

    bool isFull(){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }else{
            return true;
        }
    }

    int getFront(){
        if(front == rear){
          return -1;
        }
          return arr[front];
    }

    void display(){
        cout << "Queue:  ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){

 Queue *q = new Queue(6);

   q->enqueue(1);
   q->enqueue(11);
   q->enqueue(111);
   q->enqueue(1111);

   cout << "THe front element is:" << q->getFront() << endl;

   q->enqueue(11111);

   cout << "Deleting element: " << endl;
   cout << "Dequeued element: " << q->dequeue() << endl;
   cout << "Dequeued element: " << q->dequeue() << endl;

   cout << "THe front element is:" << q->getFront() << endl;

   q->enqueue(111111);

   q->display();

   return 0;
}