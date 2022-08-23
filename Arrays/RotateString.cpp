/*Rotate String
Rotate string
Problem Description

Given a string A, rotate the string B times in clockwise direction and return the string.



Problem Constraints
1 <= |A| <= 105

1 <= B <= 109

String A consist only of lowercase characters.



Input Format
First and only argument is a string A.



Output Format
Return a string denoting the rotated string.



Example Input
Input 1:

 A = "scaler"
 B = 2
Input 2:

 A = "academy"
 B = 7


Example Output
Output 1:

 "erscal"
Output 2:

 "academy"


Example Explanation
Explanation 1:

 Rotate the given string twice so the string becomes "erscal".*/

================================================================
def solve(self, A, B):
        n=len(A)
        B=B%n
        A=A[n-B:]+A[0:n-B]
        return A

Another method:
==============

void antirotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void clockrotate(string &s, int B)
{
   antirotate(s, s.length()-B);
}

string Solution::solve(string A, int B) {
    int n = A.size();
    B = B%n;
    clockrotate(A, B);
    return A;
}
