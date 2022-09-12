/*
Problem Description
Bob has an array A of N integers. Initially, all the elements of the array are zero. Bob asks you to perform Q operations on this array.

You have to perform three types of query, in each query you are given three integers x, y and z.

if x = 1: Update the value of A[y] to 2 * A[y] + 1.
if x = 2: Update the value A[y] to ⌊A[y]/2⌋ , where ⌊⌋ is Greatest Integer Function.
if x = 3: Take all the A[i] such that y <= i <= z and convert them into their corresponding binary strings. Now concatenate all the binary strings and find the total no. of '1' in the resulting string.
Queries are denoted by a 2-D array B of size M x 3 where B[i][0] denotes x, B[i][1] denotes y, B[i][2] denotes z.



Problem Constraints
1 <= N, Q <= 100000
1 <= y, z <= N
1 <= x <= 3



Input Format
The first argument has the integer A.
The second argument is a 2d matrix B, of size Q x 3, representing the queries.



Output Format
Return an array of integers where ith index represents the answer of the ith type 3 query.



Example Input
Input 1:

 A = 5
 B = [   
        [1, 1, -1]
        [1, 2, -1]
        [1, 3, -1]   
        [3, 1, 3] 
        [3, 2, 4]   
     ]
Input 2:

 A = 5
 B = [   
        [1, 1, -1]
        [1, 2, -1]
        [3, 1, 3]
        [2, 1, -1]
        [3, 1, 3]   
     ]


Example Output
Output 1:

 [3, 2]
Output 2:

 [2, 1]
*/

==================================================

void update2(vector<int> &tree,int ind,int low,int high,int i) {
    if(low==high) {
        tree[ind] = 1;
        return ;
    }
    int mid = low+(high-low)/2;
    if(low<=i && i<=mid) {
         update2(tree,2*ind+1,low,mid,i);
    } else {
        update2(tree,2*ind+2,mid+1,high,i);
    }
    tree[ind] = tree[2*ind+1]+tree[2*ind+2];
}
void update1(vector<int> &tree,int ind,int low,int high,int i) {
    if(low==high) {
        tree[ind]+=1;
        return ;
    }
    int mid = low+(high-low)/2;
    if(low<=i && i<=mid) {
         update1(tree,2*ind+1,low,mid,i);
    } else {
        update1(tree,2*ind+2,mid+1,high,i);
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
void buildSegTree(vector<int> &tree,int ind,int low,int high) {
    if(low==high) {
        tree[ind] = 0;
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
            if(B[i][0]==1) {
                update1(tree,0,0,n-1,B[i][1]-1);
            } else if(B[i][0]==2) {
                update2(tree,0,0,n-1,B[i][1]-1);
            }
             else {
                int val = rangeQuery(tree,0,0,n-1,B[i][1]-1,B[i][2]-1);
                ans.push_back(val);
            }
    }
    return ans;
}