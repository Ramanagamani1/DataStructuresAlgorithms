/*
Problem Description

Given an array A, containing positive integers. You need to perform some queries on it.

You will be given Q Queries. Each query will have one string and two integers. Each Query can be of two type :

"C" X Y - Here "C" says that we need to Change the integer at position X to integer Y.
"A" X Y - Here "A" say that we are Asked number of primes in the the range : [X, Y] (inclusive)
For each Query of type 2, you need to calculate an integer denoting the answer to it.

NOTE:

Assume 1-indexing for all queries.
Your code will be run on multiple test cases (< 10). Make sure to come up with an optimised solution and take care of clearing global variables.


Problem Constraints

1 <= Size of A <= 4 * 104

1 <= A[i] <= 106

1 <= Number of Queries (Size of B, C, D) <= 5 * 104



Input Format

First argument is an integer array A.
Second argument is a string array B.
Third argument is an integer array C.
Fourth argument is an integer array D.

In the i-th query, B[i] dentotes the string, C[i] denotes X and D[i] denotes Y.



Output Format

Return an integer array, where each of the element represents the answer to the queries of type 2, in chronological order.



Example Input

Input 1:

 A = [1, 3, 121, 20, 17, 26, 29]
 B = ["A", "C", "A"]
 C = [1, 3,  1]
 D = [7, 19, 7]
Input 2:

 A = [7, 15, 11]
 B = ["C", "A"]
 C = [2, 2]
 D = [9, 3]


Example Output

Output 1:

 [3, 4]
Input 2:

 [1]

*/
==========================================================================
void calculatePrimes(vector<int> &prime, int mx) {
    for(int p=2;p*p<=mx;p++) {
        if(prime[p]) {
            for(int i=p*p;i<=mx;i+=p) {
                prime[i]=0;
            }
        }
    }
}
void update1(vector<int> &tree,int ind,int low,int high,int i,int val,vector<int> &prime) {
    if(low==high) {
        tree[ind] = prime[val];
        return ;
    }
    int mid = low+(high-low)/2;
    if(low<=i && i<=mid) {
         update1(tree,2*ind+1,low,mid,i,val,prime);
    } else {
        update1(tree,2*ind+2,mid+1,high,i,val,prime);
    }
    tree[ind] = tree[2*ind+1]+tree[2*ind+2];
}
int rangeQuery(vector<int> &tree,int ind,int low,int high,int qL,int qR) {
       if(high<qL || low>qR) {
           return 0;
       }
       if(qL<=low && high<=qR) {
           return tree[ind];
       }
       int mid = low+(high-low)/2;
       return rangeQuery(tree,2*ind+1,low,mid,qL,qR)+rangeQuery(tree,2*ind+2,mid+1,high,qL,qR);
}
void buildSegTree(vector<int> &tree,int ind,int low,int high,vector<int> &A,vector<int> &prime) {
    if(low==high) {
        tree[ind] = prime[A[low]];
        return ;
    } else {
          int mid = low+(high-low)/2;
          buildSegTree(tree,2*ind+1,low,mid,A,prime);
          buildSegTree(tree,2*ind+2,mid+1,high,A,prime);
          tree[ind] = tree[2*ind+1]+ tree[2*ind+2];
    }
}
vector<int> Solution::solve(vector<int> &A, vector<string> &B, vector<int> &C, vector<int> &D) {
    vector<int> prime(1000001,1);
    calculatePrimes(prime,1000000);
    int n=A.size();
    vector<int> tree(4*n,0);
    buildSegTree(tree,0,0,n-1,A,prime);
    vector<int> ans;
    for(int i=0;i<B.size();i++) {
        if(B[i]=="A") {
            int x = rangeQuery(tree,0,0,n-1,C[i]-1,D[i]-1);
            ans.push_back(x);
        }
         else {
           update1(tree,0,0,n-1,C[i]-1,D[i],prime);
         }
    }
    return ans;
}
