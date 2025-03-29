#include<iostream>
using namespace std;
  

  int main(){
  int count = 0;
  int n;

  while(n){
    n = (n)%(n-1);
    count++;
  } 
  return count;
  }