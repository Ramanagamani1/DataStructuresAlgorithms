/*
Problem Description

Given a binary string A of size N and an integer matrix B of size Q x 3.

Matrix B has Q queries:

For queries of type B[i][0] = 1, flip the value at index B[i][1] in A if and only if the value at that index is 0 and return -1.
For queries of type B[i][0] = 0, Return the value of the binary string from index B[i][1] to B[i][2] modulo 3.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints

1 <= N <= 100000
1 <= Q <= 200000
1 <= B[i][1], B[i][2] <= N
B[i][1] <= B[i][2]



Input Format

The first argument given is the string A.
The second argument given is the integer matrix B of size Q * 3.



Output Format

Return an array of size Q where ith value is answer to ith query.



Example Input

Input 1:

 A = 10010
 B = [  [0, 3, 5]
        [0, 3, 4]
        [1, 2, -1]
        [0, 1, 5]
     ]
Input 2:

 A = 11111
 B = [
        [0, 2, 4]
        [1, 2, -1
        [0, 2, 4]]
     ]


Example Output

Output 1:

 [2, 1, -1, 2]
Output 2:

 [1, -1, 1]

*/

--------------------------------------------------------------------------------
void update(vector<int> &tree,int ind,int low,int high,int i,int value) {
    if(low==high) {
        tree[ind] = value;
        return ;
    }
    int mid = low+(high-low)/2;
    if(i<=mid) {
         update(tree,2*ind+1,low,mid,i,value);
    } else {
        update(tree,2*ind+2,mid+1,high,i,value);
    }
    int num_bits = high-mid;
    int val = num_bits%2 == 0 ? 1: 2;
    tree[ind] = ((tree[2*ind+1]*val)%3 + tree[2*ind+2])%3; 
}
int rangeQuery(vector<int> &tree,int ind,int low,int high,int qL,int qR) {
        if(high<qL || low>qR) {
           return 0;
       }
       if(qL<=low && high<=qR) {
           return tree[ind];
       }
       int mid = low+(high-low)/2;
       if(qR<=mid) {
           return rangeQuery(tree,2*ind+1,low,mid,qL,qR);
       } else if(qL<=mid && mid<=qR) {

       int left = rangeQuery(tree,2*ind+1,low,mid,qL,qR);
       int right = rangeQuery(tree,2*ind+2,mid+1,high,qL,qR);

       int num_bits = min(qR,high)-mid;
       int val = num_bits%2==0 ? 1: 2;

       return ((left*val)%3+right)%3;
       } 
}
int buildSegTree(vector<int> &tree,int ind,int low,int high,string &A) {
    if(low==high) {
        tree[ind] = A[low];
        return A[low];
    }
    int mid = low+(high-low)/2;
    buildSegTree(tree,2*ind+1,low,mid,A);
    buildSegTree(tree,2*ind+2,mid+1,high,A);

    int num_bits = high-mid;
    int val = num_bits%2 == 0 ? 1:2;

    tree[ind] = ((tree[2*ind+1]*val)%3 + tree[2*ind+2])%3;
    return tree[ind];
}
vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    int n=A.size();
    vector<int> tree(4*n,0);
    buildSegTree(tree,0,0,n-1,A);
    vector<int> ans;
    for(int i=0;i<B.size();i++) {
        if(B[i][0]==0) {
            int val = rangeQuery(tree,0,0,n-1,B[i][1]-1,B[i][2]-1);
            ans.push_back(val);
        } else {
            update(tree,0,0,n-1,B[i][1]-1,1);
            ans.push_back(-1);
        }
    }
    return ans;
}
