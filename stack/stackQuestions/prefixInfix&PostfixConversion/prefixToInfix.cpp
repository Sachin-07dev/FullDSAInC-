#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s){
    int n = s.length(); 
    int i =n-1;
    stack<string> st;
    for (int i = n-1; i>=0; i--) {
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

            st.push("(" + top1 + s[i] + top2 + ")");
        }
    }
    return st.top();
}

int main(){

string s;
cout << "Enter the string:";
cin >> s;

string result = prefixToInfix(s);
cout << "The prefix of" << s << "is:" << result << endl;

return 0;
}