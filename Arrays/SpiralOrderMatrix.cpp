/*Spiral Order Matrix II
Problem Description

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Problem Constraints
1 <= A <= 1000



Input Format
First and only argument is integer A


Output Format
Return a 2-D matrix which consists of the elements in spiral order.



Example Input
Input 1:

1
Input 2:

2


Example Output
Output 1:

[ [1] ]
Output 2:

[ [1, 2], [4, 3] ]


Example Explanation
Explanation 1:

 
Only 1 is to be arranged.
Explanation 2:

1 --> 2
      |
      |
4<--- 3
*/

============================================================================

class Solution:
	# @param A : integer
	# @return a list of list of integers
	def generateMatrix(self, A):
        res=[]
        if A==1:
            res.append([1])
            return res
        for i in range(A):
              res.append([0]*A)
        r,c=A,A
        k,l=0,0
        m,n=A,A
        num=1
        while k<r-1 and l<c-1:
              for i in range(l,n):
                   res[k][i]=num
                   num+=1
              k=k+1
              for j in range(k,m):
                   res[j][n-1]=num
                   num+=1
              n=n-1
              for s in range(n-1,l-1,-1):
                   res[m-1][s]=num
                   num+=1
              m=m-1
              for t in range(m-1,k-1,-1):
                   res[t][l]=num
                   num+=1
              l=l+1
        return res
         