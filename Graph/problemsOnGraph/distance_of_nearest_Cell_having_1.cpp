//Question: you are given n*m matrix and have to return an matrix of same size that
// contains the distance of nearest cell having one for {i,j}.

//The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number
// and column number of the current cell, and i2, j2 are the row number and column number
// of the nearest cell having value 1. There should be atleast one 1 in the grid.

/*input: grid: [
                [ 0, 0, 0]
                [ 0, 1, 0]
                [ 1, 0, 1]
               ]

  output : dist: [
                  [2, 1, 1]
                  [1, 0, 1]
                  [0, 1, 0]
                 ]
                */

#include<iostream>
#include<vector>
using namespace std;

vector<>
int main(){

    int n, m;
    cout << "Enter the n & m: ";
    cin >> n >>m;


    vector<vector<int>> grid;
    cout << "Enter the data of the grid: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> ans = nearestDistance(n,m,grid);
    cout << "Resultant Matrix: ";
    for(int i=0;i<n;i++){
        cout << "[";
        for(int j=0;j<m;j++){
            cout << grid[i][j];
        }cout << "]" << endl;
    }

}