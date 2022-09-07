/*
Problem Description

Given an integer A denoting the size of the array consisting all ones.

You are given Q queries, for each query there are two integer x and y:

If x is 0, then update the value of array at index y to 0.
If x is 1, then output the index of yth one in the array. If there is no such index then output -1.
NOTE 1: There will atleast 1 query where value of x is 1.



Problem Constraints

1 <= A, Q <= 105

0 <= x <= 1

1 <= y <= A



Input Format

First argument is an integer A denoting the size of array.

Second argument is a 2-D array B of size Q x 2 where B[i][0] denotes x and B[i][1] denotes y.



Output Format

Return an integer array denoting the output of each query where x is 1.



Example Input

Input 1:

 A = 4
 B = [ [1, 2],
       [0, 2],
       [1, 4] ]
Input 2:

 A = 5
 B = [ [0, 3],
       [1, 4],
       [0, 3],
       [1, 5] ] 


Example Output

Output 1:

 [2, -1]
Output 2:

 [5, -1]

*/
void update(vector<int> &tree,int ind,int low,int high,int i) {
    if(low==high) {
        tree[ind] = 0;
        return ;
    }
    int mid = low+(high-low)/2;
    if(low<=i && i<=mid) {
         update(tree,2*ind+1,low,mid,i);
    } else {
        update(tree,2*ind+2,mid+1,high,i);
    }
    tree[ind] = tree[2*ind+1]+tree[2*ind+2];
}
int rangeQuery(vector<int> &tree,int ind,int low,int high,int k) {
       if(k>tree[ind]) {
           return -1;
       }
       if(low==high) {
            return low+1;
       }
       int mid = low+(high-low)/2;
       int left = tree[2*ind+1];
       if(left >=k) {
           return rangeQuery(tree,2*ind+1,low,mid,k);
       } else {
           return rangeQuery(tree,2*ind+2,mid+1,high,k-left);
       }
}

void buildSegTree(vector<int> &tree,int ind,int low,int high) {
    if(low==high) {
        tree[ind] = 1;
        return ;
    } else {
          int mid = low+(high-low)/2;
          buildSegTree(tree,2*ind+1,low,mid);
          buildSegTree(tree,2*ind+2,mid+1,high);
          tree[ind] = tree[2*ind+1]+ tree[2*ind+2];
    }
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    int n=A;
    vector<int> tree(4*n,0);
    buildSegTree(tree,0,0,n-1);
    vector<int> ans;

    for(int i=0;i<B.size();i++) {
            if(B[i][0]==0) {
                update(tree,0,0,n-1,B[i][1]-1);
            } else {
                int val = rangeQuery(tree,0,0,n-1,B[i][1]);
                ans.push_back(val);
            }
    }
    return ans;
} 
