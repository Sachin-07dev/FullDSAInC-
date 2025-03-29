#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
 int n = v.size();
 int s = 0, e = n-1;
  
  while(s<=e){
 
    swap(v[s], v[e]);
    s++;
    e--;
}

   return v;
}

void print(vector<int> v){
   int n = v.size();
  for(int i=0; i<n; i++){
    cout << v[i] <<" ";

  }
  cout << endl;
}
int main(){

  vector<int> v;

  v.push_back(11);
  v.push_back(7);
  v.push_back(3);
  v.push_back(12);
  v.push_back(4);


  vector<int> ans = reverse(v);
  
  cout <<"Printing reverse Array" <<endl;

  print(ans);

  return 0;

}