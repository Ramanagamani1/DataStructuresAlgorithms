/*
Problem Description

Given an array of integers A. Find and return the number of subarrays whose xor values is less than B.
NOTE: As the answer can be very large, return the answer modulo (109+7).



Problem Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 105
1 <= B <= 106



Input Format

The argument given is the integer array A
Second argument is an integer B.



Output Format

Return an integer denoting the number of subarrays whose xor values is less than B.



Example Input

Input 1:

 A = [8, 3, 10, 2, 6, 7, 6, 9, 3]
 B = 3
Input 2:

 A = [9, 4, 3, 11]
 B = 7


Example Output

Output 1:
 5
Output 2:

 3


Example Explanation

Explanation 1:

 Generate all the subarrays and their corresponding xor and there are only 5 such subaraays which have xor less than 3.
Explanation 2:

 Subarrays with xor < 7 are : [9, 4, 3, 11], [4] and [3].
 So, the answer is 3. */

int mod=1000000007;
struct TrieNode {
    TrieNode *left;
    TrieNode *right;
    int leftcount =0 ,rightcount =0;
};

TrieNode * newNode() {
    TrieNode * temp = new TrieNode;
    temp -> leftcount = 0;
    temp -> rightcount = 0;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void insert(TrieNode * root, int x) {
    TrieNode * temp = root;
    for (int i = 31; i >= 0; i--) {
           int bit = (x >> i) & 1;
           if(bit==0) {
               temp->leftcount++;
               if(temp->left==NULL) {
                   temp->left = newNode();
               }
               temp=temp->left;
           } else {
              temp->rightcount++;
              if(temp->right==NULL)
                 temp->right = newNode();
              temp=temp->right;
           }
    }   
}

int query(TrieNode *root,int element,int B) {
    TrieNode * temp = root;
    int ans = 0;
    for(int i=31;i>=0 && temp!=NULL ;i--) {
           int b_bit = (B >> i) & 1;
           int y_bit = (element >> i) & 1;
            
           if(b_bit) {
               if(y_bit) {
                   ans = (ans+temp->rightcount)%mod;
                   if(temp->left==NULL)
                       return ans;
                   temp = temp->left;
               }
               else {
                   ans = (ans+temp->leftcount)%mod;
                   if(temp->right==NULL)
                      return ans;
                   temp = temp->right;
               }
           } 
           else {
               if(y_bit) {
                   if(temp->right==NULL)
                      return ans;
                   temp=temp->right;
               } else {
                   if(temp->left==NULL) 
                        return ans;
                   temp = temp->left;
               }
           }
           
           
    }
    return ans%mod;
}
    
int Solution::solve(vector<int> &A, int B) {
    TrieNode *root = newNode();

    vector<int> prefix(A.size()+1,0);
    
    for(int i=1;i<prefix.size();i++) {
        prefix[i] = prefix[i-1]^A[i-1];
    }

    insert(root,prefix[0]);

    int ans=0;
    for(int i=1;i<prefix.size();i++) {
        ans= (ans+query(root,prefix[i],B))%mod;
        insert(root,prefix[i]);
    }

    return ans%mod;
}

/*
typedef struct TrieNode {
    int val;
    int cnt;
    TrieNode * bit[2];
}TrieNode;

TrieNode * newNode(int b) {
    TrieNode * p = new TrieNode;
    p -> val = b;
    p -> cnt = 0;
    p -> bit[0] = p -> bit[1] = NULL;
    return p;
}

vector < int > intToBinary(int k) {
    vector < int > V(20, 0);
    int i = 0;
    while (k > 0) {
        V[i] = k % 2;
        k /= 2;
        i++;
    }
    reverse(V.begin(), V.end());
    return V;
}

void insertValue(int p, TrieNode * root) {
    vector < int > V = intToBinary(p);
    TrieNode * curr = root;
    for (int i = 0; i < 20; ++i) {
        if (curr -> bit[V[i]] == NULL)
            curr -> bit[V[i]] = newNode(V[i]);
        curr = curr -> bit[V[i]];
        curr -> cnt++;
    }
    return;
}

int query(int p, int k, TrieNode * root) {
    vector < int > P = intToBinary(p);
    vector < int > K = intToBinary(k);
    TrieNode * curr = root;
    long long int ans = 0;
    for (int i = 0; i < 20 && curr != NULL; ++i) {
        if (K[i] == 0) {
            if (P[i] == 1)
                curr = curr -> bit[1];
            else curr = curr -> bit[0];
        } else {
            if (P[i] == 1) {
                if (curr -> bit[1] != NULL)
                    ans += curr -> bit[1] -> cnt;
                curr = curr -> bit[0];
            } else {
                if (curr -> bit[0] != NULL)
                    ans += curr -> bit[0] -> cnt;
                curr = curr -> bit[1];
            }
        }
    }
    if (curr != NULL) {
        ans += curr -> cnt; //cout << ans << " "; 
    }
    return ans;
}

int Solution::solve(vector < int > & A, int B) {
    if (A.size() == 0)
        return 0;
    TrieNode * root = newNode(-1);
    insertValue(0, root);
    int k = 0, ans;
    long long int res = 0, mod = 1e9 + 7, s;
    vector < int > XOR;
    XOR.push_back(0);
    for (int i = 0; i < A.size(); ++i) {
        k = k ^ A[i];
        XOR.push_back(k); //cout << k << " : ";
        s = res;
        res = (res + query(k, B - 1, root)) % mod; //cout << res-s << " :: "; 
        insertValue(k, root);
    }
    ans = res;
    return ans;
}*/