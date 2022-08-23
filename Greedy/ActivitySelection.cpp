/******************************************************************************
Activity Selection Problem:(Greedy)
Given two integer arrays A and B of size N.

There are N activities where A[i] denotes the start time of the ith activity and B[i] denotes the finish time of the ith activity.

Your task is to select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.


Input Format

The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format

Return the maximum number of activities that can be performed by a single person.
Constraints

1 <= N <= 100000
0 <= A[i] <= B[i] <= 2*10^9 
For Example

Input 1:
    A = [5, 1, 3, 0, 5, 8]
    B = [9, 2, 4, 6, 7, 9]
Output 1:
    4
    Explanation 1:
        Activites 2, 3, 5 and 6 can be selected (1- based indexing).

Input 2:
    A = [17, 8, 14, 24, 10, 8, 1, 30]
    B = [18, 45, 24, 27, 18, 10, 38, 35]
Output 2:
    4

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity{
    int start;
    int end;
};

bool compare(Activity a1,Activity a2){
    return (a1.end<a2.end);
}

int solve(vector<int> &A, vector<int> &B) {
    Activity arr[6];
    for(int i=0;i<A.size();i++){
        arr[i].start=A[i];
        arr[i].end=B[i];
    }
    sort(arr,arr+A.size(),compare);
    int count=1;
    int i=0,j=1;
    while(j<A.size()){
        if(arr[j].start>=arr[i].end){
            count+=1;
            i=j;
            j+=1;
        }
        else
           j+=1;
    }
    return count;
}

int main()
{
    vector<int> A = { 5, 1, 3, 0, 5, 8 };
    vector<int> B = { 9, 2, 4, 6, 7, 9 };
    int x = solve(A, B);
    cout<<x;
    return 0;
}
