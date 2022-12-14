/*Multiplication of previous and next
Given an array of integers A, update every element with multiplication of previous and next elements with following exceptions. a) First element is replaced by multiplication of first and second. b) Last element is replaced by multiplication of last and second last.


Input Format

The only argument given is the integer array A.
Output Format

Return the updated array.
Constraints

1 <= length of the array <= 100000
-10^4 <= A[i] <= 10^4 
For Example

Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    [2, 3, 8, 15, 20]

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    [85, 500, 187, 1100]*/

====================================================

def solve(self, A):
        if len(A)==1:
            return A
        res=[]
        res.append(A[0]*A[1])
        for i in range(1,len(A)-1):
            res.append(A[i-1]*A[i+1])
        res.append(A[i]*A[-1])
        return res