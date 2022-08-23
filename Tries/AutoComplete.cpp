/*
Problem Description
There is a dictionary A of N words, and ith word has a unique weight Wi.

Another string array B of size M contains the prefixes. For every prefix B[i], output atmost 5 words from the dictionary A that start with the same prefix.

Output the words in decreasing order of their weight.

NOTE: If there is no word that starts with the given prefix output -1.



Problem Constraints
1 <= T <= 5

1 <= N <= 20000
1 <= M <= 10000

1 <= Wi <= 106

1 <= length of any string either in A or B <= 30



Input Format
First line is an integer T denoting the number of test cases.
For each test case,

First line denotes two space seperated integer N and M.
Second line denotes N space seperated strings denoting the words in dictionary.
Third line denotes N space seperated integers denoting the weight of each word in the dictionary.
Fourth line denotes M space seperated integers denoting the prefixes.


Output Format
For every prefix B[i], print the space seperated output on a new line.

NOTE: After every output there should be a space.



Example Input
Input 1:

 1
 6 3
 abcd aecd abaa abef acdcc acbcc
 2 1 3 4 6 5
 ab abc a
Input 2:

 1
 5 3
 aaaa aacd abaa abaa aadcc
 3 4 1 2 6 
 aa aba abc


Example Output
Output 1:

 abef abaa abcd 
 abcd 
 acdcc acbcc abef abaa abcd 
Output 2:

 aadcc aacd aaaa 
 abaa abaa 
 -1 
*/

#include<iostream>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *child[26];
    vector<int> wordIndexes;

    bool containsKey(char ch) {
        return child[ch-'a']!=NULL;
    }

    void put(char ch,Node *node) {
        child[ch-'a'] = node;
    }

    Node *get(char ch) {
        return child[ch-'a'];
    }

    
};
class Trie {
    private : Node *root;
    public :

    Trie() {
        root = new Node();
    }

    void insert(string word,int j) {
        Node *curr = root;
        for(int i=0;i<word.length();i++) {
            if(!curr->containsKey(word[i])) {
                curr->put(word[i],new Node());
            }
            
            curr = curr->get(word[i]); 
            if(curr->wordIndexes.size()<5)   
            curr->wordIndexes.push_back(j); 
        }
    }

    vector<int> getTopFive(string word) {
           Node *curr = root;
           for(int i=0;i<word.size();i++) {
                  if(!curr->containsKey(word[i]))
                      return {};
                  else
                    curr=curr->get(word[i]);
           }
           return curr->wordIndexes;
    }
};

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
           int n,m;
           cin>>n>>m;

           vector<string> A(n);
           vector<int> wt(n);
           vector<string> B(m);

           for(int i=0;i<n;i++) {
               cin>>A[i];     
           }

           for(int i=0;i<n;i++) {
                cin>>wt[i];
           }

           for(int i=0;i<m;i++) {
               cin>>B[i];
           }

           vector<pair<int,string>> mp;
           for(int i=0;i<n;i++) {
               mp.push_back({wt[i],A[i]});
           }
           sort(mp.rbegin(),mp.rend());

           Trie *trie = new Trie();
           for(int i=0;i<n;i++) {
                  trie->insert(mp[i].second,i);
           }

           vector<int> ans;
           for(int i=0;i<B.size();i++) {
                 ans = trie->getTopFive(B[i]);
                 if(ans.size()==0) {
                     cout<<-1<<" ";
                 } else {
                    for(int i=0;i<ans.size();i++) {
                        cout<<mp[ans[i]].second<<" ";
                    }
                 }
                 cout<<endl;
           }
    }
    return 0;
}