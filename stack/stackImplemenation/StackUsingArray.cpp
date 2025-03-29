#include<iostream>
using namespace std;

class Stack{

    public:
      int *arr;
      int top;
      int size;

        Stack(int n){
        size = n;
        arr= new int[n];
        top = -1;
      }

      void push(int val){
        if(top == size-1){
            cout << "Stack Overflow";
            return;
        }
        arr[top] = val;
        top++;
      }

      int pop(){
        if(top == -1){
            cout << "Stack Underflow";
            return;
        }
        int val = arr[top];
        top--;
        return val;
      }

      int peek(){
        if(top == -1){
            cout << "Stack is empty";
            return;
        }
        return arr[top];
      }
};
int main(){

int cases;
cout << "Enter the number of cases:";
cin >> cases;

while(cases--){
    int n;
    cout <<"Enter the size of stack:";
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}
return 0;
}