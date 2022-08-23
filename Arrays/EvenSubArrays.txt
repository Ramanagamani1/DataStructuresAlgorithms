/*Even Subarrays
Problem Description

You are given an integer array A.

Decide whether it is possible to divide the array into some subarrays of even length such that first and last element of all subarrays will be even?<

Return "YES" if it is possible otherwise return "NO" (without quotes).



Problem Constraints
1 <= |A|, A[i] <= 106



Input Format
The first and the only input argument is an integer array, A.



Output Format
Return a string "YES" or "NO" denoting the answer.



Example Input
Input 1:

 A = [2, 4, 8, 6]
Input 2:

 A = [2, 4, 8, 7, 6]


Example Output
Output 1:

 "YES"
Output 2:

 "NO"


Example Explanation
Explanation 1:

 We can divide A into [2, 4] and [8, 6].
Explanation 2:

 There is no way to divide the array into even length subarrays.*/

==================================================================================
string Solution::solve(vector<int> &A) {
    
    int n = (int)A.size();
    /* 
        If the first and the last element is even and
        thesize of the array is even then only the answer will be "YES"
    */
    if(A[0]%2 == 0 and A[n-1]%2 == 0 and n%2 == 0)
        return "YES";
    // Otherwise answer will be "NO", as we can't divide the array into subarrays that met required conditions.
    return "NO";
}