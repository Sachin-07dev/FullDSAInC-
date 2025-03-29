#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
      queue<int> reverseQueue(queue<int> q, int k){

        //step1: fetching the first k values from queue and pushing them into stack

        stack<int> s;
        for(int i=0;i<k;i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }

        //step2: fetch the values from stack and push back into the queue
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
        }

        //step3: fetch first q.size()-k element from queue and push back into the same queue
        int t = q.size()-k;
        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
      }

};
int main(){

int m;
cout << "Enter m:";
cin >> m;

while(m-->0){
    int n,k;
    cout << "Enter n&k:";
    cin >> n >> k;
    queue<int> q;
    cout << "Enter values of queue q:";
    while(n-- >0){
        int a;
        cin >> a;
        q.push(a);
    }
    Solution obj;
    queue<int> ans = obj.reverseQueue(q,k);
    while(!ans.empty()){
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;

cout <<"~" <<"\n";    
}
return 0;
}