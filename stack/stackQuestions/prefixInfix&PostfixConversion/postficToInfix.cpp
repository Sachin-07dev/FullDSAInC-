#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string s){
    int n = s.length(); 
    int i =0;
    stack<string> st;
    for (int i = 0; i < n; i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z')||
            (s[i] >= '0' && s[i] <= '9')){
            string top(1,s[i]);    
            st.push(top);
        }else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            st.push("(" + top2 + s[i] + top1 + ")");
        }
    }
    return st.top();
}

int main(){

string s;
cout << "Enter the string:";
cin >> s;

string result = postfixToInfix(s);
cout << "The prefix of" << s << "is:" << result << endl;

return 0;
}