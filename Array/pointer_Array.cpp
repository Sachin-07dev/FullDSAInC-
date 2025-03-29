#include<iostream>
using namespace std;
int main(){

// int arr[] = {1,32,3,4,22,32};
//cout << " the address:  " << arr <<endl;
//cout << " the value at the address: " << arr[0] << endl;
//cout << " the address of the array: " << &arr[0] << endl;

char  ch[10] = "abcde";

char *ptr = &ch[0];

cout << ch << endl;
cout << *ch << endl;
cout << &ch << endl;
cout << ptr << endl;
cout << *ptr << endl;
cout << &ptr << endl;

char temp = 'a';
char *p = &temp;

cout << p << endl;
cout << *p << endl;
cout << &p <<endl;
cout << temp << endl;
cout << &temp << endl;

return 0;
}