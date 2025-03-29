#include<iostream>
using namespace std;

void reverse(char name[], int n){
  int s=0, e=n-1;
  while(s<=e){
    swap(name[s++], name[e--]);
  }
  }


int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }
   return count;
}

int main(){
    char name[20];

    cout << "enter your name" << endl;
    cin >> name;

    cout <<" your name is " <<" ";
    cout << name << endl;

    int len = getLength(name);
    cout << " length :" << getLength(name) << endl;

    reverse(name, len);
    cout <<" your name is " <<" ";
    cout << name << endl;
    return 0;


}