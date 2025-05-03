// You are given an integer n, which indicates that there are n courses labeled 
//from 1 to n. You are also given a 2D integer array of relations where 
//relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has 
//to be completed before course nextCoursej (prerequisite relationship). 
//Furthermore, you are given a 0-indexed integer array time, where time[i] denotes 
//how many months it takes to complete the (i+1)th course.

// You must find the minimum number of months needed to complete all the courses by
// following these rules:

// You may start taking a course at any time if the prerequisites are met.
// Any number of courses can be taken at the same time.
// Return the minimum number of months needed to complete all the courses.

// Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).
// Example 1:

// Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
// Output: 8

// Explanation: The figure above represents the given graph and the time required to complete each course. 
// We start course 1 and course 2 simultaneously at month 0.
// Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
// Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.

// Example 2:
// Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
// Output: 12

// Explanation: The figure above represents the given graph and the time required to complete each course.
// You can start courses 1, 2, and 3 at month 0.
// You can complete them after 1, 2, and 3 months respectively.
// Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
// Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
// Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.

// Input format :
// The input consists of the following components:
// The first line of input consists of an integer n, representing the total number of tasks.
// The second line of input consists of an integer r, representing the number of dependencies between tasks.
// The next n lines consist of two space-separated integers a and b representing the relations between tasks, indicating that task b is a dependent for task a.
// The last line of input consists of an array of integers (time) representing the time required for each task where the i-th element represents the time required for task i+1.

// Output format :
// The program should output the minimum time required to complete all tasks, represented as an integer.

// Refer to the sample output for format specifications.
// Code constraints :
// 1 ≤ n ≤ 5 * 104
// 0 ≤ relations.length ≤ min(n * (n - 1) / 2, 5 * 104)
// relations[j].length == 2
// 1 ≤ prevCoursej, nextCoursej ≤ n
// prevCoursej != nextCoursej
// All the pairs [prevCoursej, nextCoursej] are unique.
// time.length == n
// 1 ≤ time[i] ≤ 104
// The given graph is a directed acyclic graph.

// Sample test cases :
// Input 1 :
// 5
// 5
// 1 5
// 2 5
// 3 5
// 3 4
// 4 5
// 1 2 3 4 5
// Output 1 :
// Minimum time required: 12

// Input 2 :
// 3
// 2
// 1 3
// 2 3
// 3 2 5
// Output 2 :
// Minimum time required: 8
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

int findMinTime(int n,int r, vector<vector<int>> &edges, vector<int> time){

    unordered_map<int, list<int>> adjList;
    vector<int> indegree(n+1,0);
    for(int i=0;i<r;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    vector<int> completionTime(n+1,0);
    queue<int> q;

    //start with node having 0 indegree
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
            completionTime[i] = time[i];
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        //traverse for neoghbouring courses
        for(auto neighbour : adjList[u]){
            completionTime[neighbour] = max(completionTime[neighbour], completionTime[u] + time[neighbour]);
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return *max_element(completionTime.begin(), completionTime.end());
}
int main(){
    
    int n,r;
    cin >> n >> r;

    vector<vector<int>> edges;

    for(int i=0;i<r;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> time(n+1);
    for(int i=1;i<=n;i++){
        cin >> time[i];
    }

    int result = findMinTime(n,r,edges, time);
    cout << "Minimum time required: " << result << endl;

    return 0;
}