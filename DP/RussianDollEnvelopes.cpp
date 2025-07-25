#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool comp(vector<int>&a,vector<int>&b){
    if(a[0] == b[0])
        return a[1]>b[1];

    return a[0]<b[0];
}

int solve(vector<vector<int>>& envelopes, int n){

    if(n==0) return 0;
    vector<int> res;
    res.push_back(envelopes[0][1]);

    for(int i=1;i<n;i++){
        if(envelopes[i][1] > res.back())
            res.push_back(envelopes[i][1]);
        else{
            //find the just bigger element index
            int index = lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
            res[index] = envelopes[i][1];
        }
    }
    return res.size();
    }
int maxEnvelopes(int n,vector<vector<int>> &envelopes){

    sort(envelopes.begin(),envelopes.end(),comp);
    solve(envelopes,n);
}
int main(){

    int n;
    cout << "Enter n";
    cin >> n;

    vector<vector<int>> envelopes(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> envelopes[i][j];
        }
    }

    cout << "Maximum number of envelopes: " << maxEnvelopes(n,envelopes);
    return 0;
}