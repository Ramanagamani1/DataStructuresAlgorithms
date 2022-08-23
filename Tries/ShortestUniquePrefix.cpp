/*Problem Description
Given a list of N words, find the shortest unique prefix to represent each word in the list.

NOTE: Assume that no word is the prefix of another. In other words, the representation is always possible



Problem Constraints
1 <= Sum of length of all words <= 106



Input Format
First and only argument is a string array of size N.



Output Format
Return a string array B where B[i] denotes the shortest unique prefix to represent the ith word.



Example Input
Input 1:

 A = ["zebra", "dog", "duck", "dove"]
Input 2:

A = ["apple", "ball", "cat"]


Example Output
Output 1:

 ["z", "dog", "du", "dov"]
Output 2:

 ["a", "b", "c"] */


// Code
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
        curr->setEnd();
    }

    /** Returns if the word is in the trie. */
    string uniquePrefix(string word) {
        Node *curr = root;
        string ans="";
        for(int i=0;i<word.length();i++) {
              if(curr->count==1) {
                  ans=ans+word.substr(0,i);
                  return ans;
              }
              curr= curr->get(word[i]);
        }
        if(curr->count==1){
            ans=ans+word;
        }
        return ans;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    Trie *trie = new Trie();
    for(int i=0;i<A.size();i++) {
          trie->insert(A[i]);
    }
    for(int i=0;i<A.size();i++) {
        ans.push_back(trie->uniquePrefix(A[i]));
    }
    return ans;
}
