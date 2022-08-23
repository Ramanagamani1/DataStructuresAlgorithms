/*
Given an array, A of integers of size N. Find the subarray AL, AL+1, AL+2, ... AR with 1<=L<=R<=N, which has maximum XOR value.

NOTE: If there are multiple subarrays with the same maximum value, return the subarray with minimum length. If the length is the same, return the subarray with the minimum starting index.



Problem Constraints
1 <= N <= 100000
0 <= A[i] <= 109



Input Format
First and only argument is an integer array A.



Output Format
Return an integer array B of size 2. B[0] is the starting index(1-based) of the subarray and B[1] is the ending index(1-based) of the subarray.



Example Input
Input 1:

 A = [1, 4, 3]
Input 2:

 A = [8]


Example Output
Output 1:

 [2, 3]
Output 2:

 [1, 1]

*/

struct Node {
    Node *child[2];
    int val=0;

    bool containsKey(int bit) {
        return child[bit]!=NULL;
    }

    Node *get(int bit) {
        return child[bit];
    }

    void put(int bit,Node *node) {
        child[bit]= node;
    }
};
class Trie {
    private : Node *root;

    public:

    Trie() {
        root=  new Node();
    }

    void insert(int num) {
        Node *curr = root;
        for(int i=31;i>=0;i--) {
            int bit = 1 & (num>>i);
            if(curr->containsKey(bit)!=NULL) {
                curr = curr->get(bit);
            } else {
                curr->put(bit,new Node());
                curr=curr->get(bit);
            }
        }
        curr->val = num;
    }

    int findXOR(int num) {
        Node *curr= root;
        int maxNum =0;
        for(int i=31;i>=0;i--) {
            int bit = 1 & (num>>i);
            if(curr->containsKey(1-bit)!=NULL) {
                maxNum = maxNum | (1<<i);
                curr = curr->get(1-bit);
            } else {
                curr = curr->get(bit);
            }
        }
        //return num^curr->val;
        return maxNum;
    }
};
vector<int> Solution::solve(vector<int> &A) {
      Trie *trie = new Trie();
      int n = A.size();
      int pre_xor = 0, maxXor = INT_MIN;

      trie->insert(0);
      vector<int> prefix(n+1,0);

      for(int i=1;i<=n;i++) {
          prefix[i] = prefix[i-1]^A[i-1];
          trie->insert(prefix[i]);
          maxXor = max(maxXor,trie->findXOR(prefix[i]));
      }

      //cout<<maxXor;

      unordered_map<int,int> mp;
      int s=1,e=1, minlen=INT_MAX;

      for(int i=0;i<prefix.size();i++) {
            int val = prefix[i]^maxXor;
            if(mp.find(val)!=mp.end()) {
                  int l = mp[val]+1;
                  int r = i;
                  int len = r-l+1;
                  if(len< minlen) {
                       minlen = len;
                       s = l;
                       e = r;
                  } else if(len==minlen && l<s) {
                      minlen = len;
                      s = l;
                      e = r;
                  }
                  /*if(e==1 || (e-s)>(i-mp[val])) {
                      s = mp[val]+1;
                      e = i;
                  }*/
            }
            mp.insert({prefix[i],i});
      }

      return {s,e};
}
