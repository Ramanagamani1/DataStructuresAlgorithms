/*
We want to make a custom contacts finder applications as part of our college project. The application must perform two types of operations:

Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name. This must store B[i] as a new contact in the application.

Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial name to search the application for. It must count the number of contacts starting with B[i].

You have been given sequential add and find operations. You need to perform each operation in order.

And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .



Problem Constraints

1 <= |A| <= 10000

1 <= |length of strings in B| <= 10



Input Format

First argument is the vector A, which denotes the type of query.

Second argument is the vector B, which denotes the string for corresponding query.



Output Format

Return an array of integers, denoting answers for each query of type 1.



Example Input

Input 1:

A = [0, 0, 1, 1]
B = ["hack", "hacker", "hac", "hak"]
Input 2:

A = [0, 1]
B = ["abcde", "abc"]


Example Output

Output 1:

 
[2, 0]
Output 2:

[1] */

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
        curr->setEnd();
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
                 curr = curr->get(word[i]);
            }   
        }
        return curr->count;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<string> &B) {

      Trie *trie = new Trie();
      vector<int> ans;
      for(int i=0;i<A.size();i++) {
          if(A[i]==0) {
               trie->insert(B[i]);
          } else {
              int val = trie->countWordsStartingWith(B[i]);
              ans.push_back(val);
          }
      }
      return ans;
}
