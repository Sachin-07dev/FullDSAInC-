// You are given a queue Q of N integers of even length, rearrange the elements by interleaving 
//the first half of the queue with the second half of the queue.

// Note : Return the modified queue after the rearrangement as vector/ArrayList .

// Example 1:

// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {2,3,4,1}.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> NewQ;
        int n = q.size();
        
        for(int i=0;i<n/2;i++){
            int val = q.front();
            q.pop();
            NewQ.push(val);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i%2 ==0){
                int val = NewQ.front();
                NewQ.pop();
                ans.push_back(val);
            }else{
                int val = q.front();
                q.pop();
                ans.push_back(val);
            }
        }
        return ans;
    }
};
int main(){

int N;
cout << "Enter the number of cases:";
cin >> N;

int n;
cout << "Enter the size of queue:";

cin >> n;

queue<int> que;
    cout << "Enter values of queue que:";
    while(n-- >0){
        int a;
        cin >> a;
        que.push(a);
    }

    Solution sol;
    vector<int> ans = sol.rearrangeQueue(que);
    cout << "Rearranged Queue: ";
        for (int a : ans) {
            cout << a << " ";
        }
        cout << endl;

return 0;
}