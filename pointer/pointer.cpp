#include<iostream>
using namespace std;

int main(){
int num = 5;
int a =num;

cout << " a before" << num <<endl;
a++;
cout << " a after " << num << endl;

int *p = &num;
cout << " after " << num << endl;
(*p)++;
cout << " before " << num << endl;


int *q= p;
cout << p << "_" << q << endl;
cout << *p << "-" << *q << endl;

return 0;
}