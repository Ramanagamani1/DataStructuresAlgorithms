/*
You are given N balloons each with a number of coins associated with them. An array of integers A represents the coins associated with the ith balloon.
You are asked to burst all the balloons. If the you burst balloon ith you will get A[left] * A[i] * A[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

NOTE: You may imagine A[-1] = A[N] = 1. They are not real therefore you can not burst them.



Problem Constraints
1 <= N <= 100
1 <= A[i] <= 100



Input Format
The only argument given is the integer array A.



Output Format
Return the maximum coins you can collect by bursting the balloons wisely.



Example Input
Input 1:

 A = [3, 1, 5, 8]
Input 2:

 A = [3, 1, 2]


Example Output
Output 1:

 167
Output 2:

 15


Example Explanation
Explanation 1:

 Burst ballon at index 1, coins collected = 3*1*5=15 , A becomes = [3, 5, 8] 
 Burst ballon at index 1, coins collected = 3*5*8=120 , A becomes = [3, 8]
 Burst ballon at index 0, coins collected = 1*3*8=24 , A becomes = [8]
 Burst ballon at index 0, coins collected = 1*8*1 = 8
 Total coins collected = 15 + 120 + 24 + 8 = 167
Explanation 2:

 Burst ballon at index 1, coins collected = 3*1*2 = 6, A becomes = [3, 2] 
 Burst ballon at index 1, coins collected = 3*2*1 = 6, A becomes = [3]
 Burst ballon at index 0, coins collected = 1*3*1 = 3
 Total coins collected = 6 + 6 + 3 = 15
*/

int f(int i,int j,vector<int> &a,vector<vector<int>> &dp) {
     if(i>j)  return 0;

     if(dp[i][j]!=-1)
       return dp[i][j];

    int maxi = INT_MIN;
    for(int k=i;k<=j;k++) {
         int coins = a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) + f(k+1,j,a,dp);
         maxi = max(maxi,coins);
    }

    return dp[i][j] = maxi;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    A.push_back(1);
    A.insert(A.begin(),1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(1,n,A,dp);
}
