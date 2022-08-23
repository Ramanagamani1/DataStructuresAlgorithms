/*Rain Water Trapped
Problem Description

Given a vector A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
First and only argument is the vector A



Output Format
Return one integer, the answer to the question



Example Input
Input 1:

A = [0, 1, 0, 2]
Input 2:

A = [1, 2]


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

1 unit is trapped on top of the 3rd element.
Explanation 2:

No water is trapped.*/

=================================================


def trap(A):
	n=len(A)
        leftmax=[0]*n
        rightmax=[0]*n
        leftmax[0]=A[0]
        rightmax[n-1]=A[n-1]
        for i in range(1,n):
             leftmax[i]=max(A[i],leftmax[i-1])
        for i in range(n-2,-1,-1):
             rightmax[i]=max(A[i],rightmax[i+1])
        trap_amount=0
        for i in range(n):
             trap_amount+=min(leftmax[i],rightmax[i])-A[i]
        return trap_amount

Another soln:
=============
int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int left = 0; int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while(left <= right){
        if(A[left] <= A[right]){
            if(A[left] >= maxleft) 
                maxleft = A[left];
            else 
                res += maxleft-A[left];
            left++;
        }
        else{
            if(A[right] >= maxright) 
                maxright = A[right];
            else 
                res += maxright - A[right];
            right--;
        }
    }
    return res;
}
