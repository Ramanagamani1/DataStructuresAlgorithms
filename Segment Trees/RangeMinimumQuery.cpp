/*
Given an integer array A of size N.

You have to perform two types of query, in each query you are given three integers x,y,z.

If x = 0, then update A[y] = z.
If x = 1, then output the minimum element in the array A between index y and z inclusive.
Queries are denoted by a 2-D array B of size M x 3 where B[i][0] denotes x, B[i][1] denotes y, B[i][2] denotes z.



Problem Constraints

1 <= N, M <= 105

1 <= A[i] <= 109

If x = 0, 1<= y <= N and 1 <= z <= 109

If x = 1, 1<= y <= z <= N



Input Format

First argument is an integer array A of size N.

Second argument is a 2-D array B of size M x 3 denoting queries.



Output Format

Return an integer array denoting the output of each query where value of x is 1.



Example Input

Input 1:

 A = [1, 4, 1]
 B = [ 
        [1, 1, 3]
        [0, 1, 5]
        [1, 1, 2] 
     ]
Input 2:

 A = [5, 4, 5, 7]
 B = [ 
        [1, 2, 4]
        [0, 1, 2]
        [1, 1, 4]
     ]


Example Output

Output 1:

 [1, 4]
Output 2:

 [4, 2] */

================================================
void update(vector<int> &tree,int ind,int low,int high,int i,int val) {
    if(low==high) {
        tree[ind] = val;
        return ;
    }
    int mid = low+(high-low)/2;
    if(low<=i && i<=mid) {
         update(tree,2*ind+1,low,mid,i,val);
    } else {
        update(tree,2*ind+2,mid+1,high,i,val);
    }
    tree[ind] = min(tree[2*ind+1],tree[2*ind+2]);
}
int rangeQuery(vector<int> &tree,int ind,int low,int high,int qL,int qR) {
       if(high<qL || low>qR) {
           return INT_MAX;
       }
       if(qL<=low && high<=qR) {
           return tree[ind];
       }
       int mid = low+(high-low)/2;
       return min(rangeQuery(tree,2*ind+1,low,mid,qL,qR),rangeQuery(tree,2*ind+2,mid+1,high,qL,qR));
}
int buildSegTree(vector<int> &tree,int ind,int low,int high,vector<int> &A) {
    if(low==high) {
        tree[ind] = A[low];
        return A[low];
    }
    int mid = low+(high-low)/2;
    tree[ind] = min(buildSegTree(tree,2*ind+1,low,mid,A),buildSegTree(tree,2*ind+2,mid+1,high,A));
    return tree[ind];
}
vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n=A.size();
    vector<int> tree(4*n,0);
    buildSegTree(tree,0,0,n-1,A);
    vector<int> ans;
    for(int i=0;i<B.size();i++) {
        if(B[i][0]==1) {
            int val = rangeQuery(tree,0,0,n-1,B[i][1]-1,B[i][2]-1);
            ans.push_back(val);
        } else {
            update(tree,0,0,n-1,B[i][1]-1,B[i][2]);
        }
    }
    return ans;
}
