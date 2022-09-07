int mod=1000000007;
struct TrieNode {
    TrieNode *children[2];
    int count = 0;
    int sumOfIndexes = 0;
};
TrieNode *newNode() {
    TrieNode * temp = new TrieNode;
    temp -> children[0]= NULL;
    temp -> children[1] = NULL;
    temp -> count = 0;
    temp -> sumOfIndexes = 0;
    return temp;
}
void insert(TrieNode *root, int num, int index) {
    for(int i=31;i>=0;i--) {
        int bit = (num >> i) & 1;
        if(root->children[bit]==NULL)
             root->children[bit] = newNode();
        root = root->children[bit];
    }
    root->sumOfIndexes= (root->sumOfIndexes+index)%mod;
    root->count++;
    
}
int query(TrieNode *root,int num,int index) {
    for(int i=31;i>=0;i--) {
        int bit = (num >> i) & 1;
        if(root->children[bit]==NULL)
             return 0;
        root = root->children[bit];
    }
    int x = root->count;
    int y = root->sumOfIndexes;
    int ans = ((index*x) - y)%mod;
    return ans;
}
int Solution::solve(vector<int> &A) {
    int ans = 0;
    int curXor = 0;
    TrieNode *trie = newNode();
    for(int i=0;i<A.size();i++) {
          
          int x = A[i];
          insert(trie,curXor,i);

          curXor = curXor^x;

          ans=(ans+query(trie,curXor,i))%mod;
    }
    return ans%mod;
}
