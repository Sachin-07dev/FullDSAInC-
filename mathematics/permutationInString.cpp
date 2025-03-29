#include<bits/stdc++.h>

 bool checkEqual( int a[26], int b[26]){
    for(int i=0; i<26; i++){
      if(a[i] != b[i]){
        return 0;
      }
       return 1;
    }
 }
  
   
   bool checkInclusion(<string> s1, <string> s2){
     int count[26] ={0};

         for(int i=0; i<s1.length(); i++){
             int index = s1[i] - 'a';
             count[index]++;
         }
         // traverse s2 string in window of size s1 length abd compare

         int i =0;
         int windowSize = s1.length();
         int count2[26] = {0};

          // running for first window 
         while(i < windowSize){
             int index = s2[i] - 'a';
            count2[index]++;
             i++;
         }
         if( checkEqual(count, count2))
         return 1;

         // aage window process karo 

          while(i< s2.length()){
              char newChar = s2[i];
              int index = newChar - 'a';
              count2[index]++;

            char Oldchar = s2[i - windowSize];
             index = Oldchar - 'a';
             count2[index]--;
              i++;

             if( checkEqual(count, count2))
             return 1;
              }
              return 0;
    }
int main(){
     string s;
     cin >> s;
     cout << checkInclusion(s1, s2) << endl;
}
