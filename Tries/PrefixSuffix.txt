/*
Problem Description

Given a list of N words denoted by string array A of size N.

You have to answer Q queries denoted by string array B, for each query you have a string S of size M, find the number of words in the list A which have string S as a prefix and suffix.

NOTE: The size M for all strings in the queries remains same.



Problem Constraints

1 <= N <= 105

1 <= |A[i]| <= 1000

1 <= Q, M <= 1000

Sum of length of all N words <= 106



Input Format

First argument is a string array A of size N denoting the list of words.

Second argument is a string array B of size Q denoting the queries.



Output Format

Return an integer array of size Q denoting the answer of each query.



Example Input

Input 1:

 A = ["ababa", "aabbvaab", "aecdsaaec", "abaaxbqaba"]
 B = ["aba", "aec", "abb", "aab"]
Input 2:

 A = ["cazqzqcaz", "cadssac", "caz"]
 B = ["caz", "cad"]


Example Output

Output 1:

 [2, 1, 0, 1]
Output 2:

 [2, 0] */


//code

struct Node {
    Node *child[26];
    bool isEnd;
    int count=0;

    bool containsKey(char ch) {
        return child[ch-'a']!=NULL;
    }

    void put(char ch,Node *node) {
        child[ch-'a'] = node;
    }

    Node *get(char ch) {
        return child[ch-'a'];
    }
    
    void setEnd() {
        isEnd = true;
    }

    void increaseCount() {
        count++;
    }
};
class Trie {
    private : Node *root;
    public :

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])) {
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
            curr->increaseCount();
        }
        //curr->setEnd();
    }

    /** Returns if the word is in the trie. */
    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *curr = root;
        int ans=0;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])){
                return 0;
            } else {
                 ans = curr->count;
                 curr = curr->get(word[i]);
            }   
        }
        return ans;
    }
};

bool check(string a, int m) {
    string x="";
    string y="";
    int n = a.size();
    if(m>n) {
        return false;
    }
    for(int i=0;i<m;i++) {
           x=x+a[i];
    }
    for(int j=n-m;j<n;j++) {
        y=y+a[j];
    }
    if(x==y){
        return true;
    }
    return false;
}

vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    Trie *trie1 = new Trie();
    int m = B[0].size();
    vector<string> filtered;
    for(int i=0;i<A.size();i++) {
          if(check(A[i],m)==true){
              filtered.push_back(A[i]);
          }
    }
    vector<int> ans(B.size(),0);
    for(int i=0;i<filtered.size();i++) {
          trie1->insert(filtered[i]);
    }
    for(int i=0;i<B.size();i++) {
         ans[i]=(trie1->countWordsStartingWith(B[i]));
    }

    return ans;
}