/*
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.



Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return an integer denoting the maximum result of A[i] XOR A[j].



Example Input
Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [5, 17, 100, 11]


Example Output
Output 1:

 7
Output 2:

 117


Example Explanation
Explanation 1:

 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:

 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117. */


//code

struct Node {
    Node *child[2];

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
        return maxNum;
    }
};
int Solution::solve(vector<int> &A) {
    Trie *trie = new Trie();
    trie->insert(A[0]);
    int maxXor = 0;
    for(int i=1;i<A.size();i++) {
          int a = trie->findXOR(A[i]);
          maxXor = max(maxXor,a);
          trie->insert(A[i]);
    }
    return maxXor;
}
