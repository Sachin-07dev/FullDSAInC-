#include<iostream>
using namespace std;
 
  char tolowerCase(char ch){
    if(ch >= 'a' && ch <= 'z')
    return ch;
    else{
         char temp =  ch - 'A' + 'a';
         return temp;
    }
  }
bool checkPalindrome( char a[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(tolowerCase( a[s] ) != tolowerCase( a[e] ))
        return 0;
        else{
            s++;
            e--;
        }
    }
    return 1;
}
 void reverse(char name[], int n ){
    int s =0, e = n-1;
    while(s<e){
        swap(name[s++], name[e--]);

    }
 }


   int getLength(char name[]){
    int count=0;
    for(int i=0; name[i] != '\0'; i++){
        count++;

    }
   }
int main(){

    char name[20];
    
    cout <<" Enter your  name" << endl;
    cin >> name;
    cout << " your name is ";
    cout << name << endl;
    int len = getLength(name);
    cout << " length:" << endl;
    reverse(name, len);
    cout <<" your name is ";
    cout << name << endl;
    
    cout << " palindrome or not  "<< checkPalindrome(name, len) << endl;
    
}