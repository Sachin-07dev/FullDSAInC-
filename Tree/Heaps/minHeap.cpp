#include<iostream>
using namespace std;

class heap{
     
    public:
      int arr[100];
      int size;

      heap(){
        arr[0] = -1;
        size = 0;
      }

      void insert(int val){
        int index = ++size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
      }

      void print(){
        cout << "Max Heap ";
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }cout << endl;
      }
};

void heapify(int arr[], int n, int i){

  int largest = i;
  int left = 2*i;
  int right = 2*i+1;

  if(left <=n && arr[largest] < arr[left]){
    largest = left;
  }else if(right <=n && arr[largest] < arr[right]){
    largest = right;
  }else{
    return;
  }

  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr,n,largest);
  }
}
int main(){
     

    heap p;
    int N;
    cout << "Enter the no of nodes in heap : ";
    cin >> N;

    int Arr[N];
    int ele;
    cout << "Enter the val of nodes of heap: ";
    for(int i=0;i<N;i++){
        cin >> ele;
        p.insert(ele);
    }

    p.print();

    int n;
    cin >> n;

    for(int i=n/2;i>=0;i--){
      heapify(Arr,n,i);
    }

return 0;
}