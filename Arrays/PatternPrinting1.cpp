/*Pattern Printing -1
Problem Description

Print a Pattern According to The Given Value of A.

Example: For A = 3 pattern looks like:

1 0 0

1 2 0

1 2 3



Problem Constraints
1 <= A <= 1000


Input Format
First and only argument is an integer denoting A.



Output Format
Return a two-dimensional array where each row in the returned array represents a row in the pattern.



Example Input
Input 1:

 A = 3
Input 2:

 A = 4


Example Output
Output :1

 [ 
   [1, 0, 0]
   [1, 2, 0]
   [1, 2, 3]
 ]
Output 2:

 [ 
   [1, 0, 0, 0]
   [1, 2, 0, 0]
   [1, 2, 3, 0]
   [1, 2, 3, 4]
 ]*/

=====================================================================

 def solve(self, A):
        res=[]
        for i in range(1,A+1):
            res.append(list(range(1,i+1)))
        return res

Another method:
===============
vector<vector<int> > Solution::solve(int A) {
    vector< vector< int > > ans(A);
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= i; j++)
            ans[i - 1].push_back(j);
        for(int j = i + 1; j <= A; j++)
            ans[i - 1].push_back(0);
    }
    return ans;
}