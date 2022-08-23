/*Given an array of words A (dictionary) and another array B (which contain some words).

You have to return the binary array (of length |B|) as the answer where 1 denotes that the word is present in the dictionary and 0 denotes it is not present.

Formally, for each word in B, you need to return 1 if it is present in Dictionary and 0 if not.

Such problems can be seen in real life when we work on any online editor (like Google Documnet), if the word is not valid it is underlined by a red line.

NOTE: Try to do this in O(n) time complexity.



Problem Constraints
1 <= |A| <= 1000

1 <= sum of all strings in A <= 50000

1 <= |B| <= 1000



Input Format
First argument is array of strings A.

First argument is array of strings B.



Output Format
Return the binary array of integers according to the given format.



Example Input
Input 1:

A = [ "hat", "cat", "rat" ]
B = [ "cat", "ball" ]
Input 2:

A = [ "tape", "bcci" ]
B = [ "table", "cci" ]


Example Output
Output 1:

[1, 0]
Output 2:

[0, 0] */


//Code

struct Node {
    Node *child[26];
    bool isEnd;

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
        }
        curr->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(curr->containsKey(word[i])) {
                 curr = curr->get(word[i]);
            }
            else
                return false;
        }
        return curr->isEnd;
    }
};
vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    Trie *trie = new Trie();
    vector<int> ans;
    for(int i=0;i<A.size();i++) {
         trie->insert(A[i]);
    }
    for(int i=0;i<B.size();i++) {
          if(trie->search(B[i])) {
              ans.push_back(1);
          } else {
              ans.push_back(0);
          }
    }
    return ans;
}
