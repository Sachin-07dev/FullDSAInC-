#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool isValidParenthesis(string str){
     int n = str.length();
     stack<char> st;

     //traverse the string
     for(int i=0;i<n;i++){
        char ch = str[i];

     // if brackets are opening brackets then push them into stack
    if(ch == '[' || ch =='{' || ch == '('){
         st.push(ch);
    }else{
            if(!st.empty()){
            char top = st.top();
            if((ch == ']' && top == '[')|| 
               (ch == '}' && top == '{')||
               (ch == ')' && top == '(')){
               st.pop();
            }else{
                return false;
            }
        }else            
        return false;
       }
    }
    return st.empty() ? true : false;
}
int main(){

string s;
cout << "Enter string:";
cin >> s;

if(isValidParenthesis(s)){
    cout << "String is valid parenthesis." << endl;
}else{
    cout << "String is not valid parenthesis." << endl;
}

return 0;
}