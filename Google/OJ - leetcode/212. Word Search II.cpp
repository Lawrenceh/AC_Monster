/* build Trie upon words dictionary and search in matrix to see if that word exists on the board */

class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    string word;
    TrieNode() {
        for (int i = 0; i < 26; i ++) 
            next[i] = NULL;
        isWord = false;
        word = "";
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    bool findWord(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (!p->next[c - 'a']) return false;
            p = p->next[c - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> res;
    void dfs(TrieNode* node, vector<vector<char> > &board, int x, int y, int m, int n, vector<vector<bool> > visited) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (visited[x][y]) return;
        visited[x][y] = true;
        char c = board[x][y];
        if (node->next[c - 'a'] == NULL) return;
        node = node->next[c - 'a'];
        if (node->isWord) {
            res.push_back(node->word);
            node->isWord = false;
        }
        dfs(node, board, x + 1, y, m, n, visited);
        dfs(node, board, x - 1, y, m, n, visited);
        dfs(node, board, x, y + 1, m, n, visited);
        dfs(node, board, x, y - 1, m, n, visited);
    }
    void buildTrie(TrieNode *root, vector<string> &words) {
        TrieNode *p;
        for (auto word: words) {
            p = root;
            for (auto c: word) {
                if (p->next[c - 'a'] == NULL) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->isWord = true;
            p->word = word;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();
        Trie *t = new Trie();
        TrieNode *root = t->root;
        buildTrie(root, words);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                vector<vector<bool> > visited(m, vector<bool>(n, false));
                dfs(root, board, i, j, m, n, visited); // start dfs, searching for valid word in Trie starting with char at (i, j)
            }
        }
        return res;
    }
};


/* below is: building Trie upon matrix and check in words dictionary, got TLE
class TrieNode {
public:
    TrieNode* next[26];
    bool isUsed;
    TrieNode() {
        isUsed = false;
        for (int i = 0; i < 26; i ++) 
            next[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    bool findWord(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (!p->next[c - 'a']) return false;
            p = p->next[c - 'a'];
        }
        // special handling for duplicate word in words
        if (p->isUsed) return false;
        // update isUsed state
        p->isUsed = true;
        return true;
    }
};

class Solution {
public:
    vector<string> res;
    void dfs(TrieNode* node, vector<vector<char> > &board, int x, int y, int m, int n, vector<vector<bool> > visited) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (visited[x][y]) return;
        visited[x][y] = true;
        char c = board[x][y];
        if (node->next[c - 'a'] == NULL) node->next[c - 'a'] = new TrieNode();
        node = node->next[c - 'a'];
        dfs(node, board, x + 1, y, m, n, visited);
        dfs(node, board, x - 1, y, m, n, visited);
        dfs(node, board, x, y + 1, m, n, visited);
        dfs(node, board, x, y - 1, m, n, visited);
    }
    void buildTrie(TrieNode* root, vector<vector<char> > &board, int i, int j, int m, int n) {
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        dfs(root, board, i, j, m, n, visited);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();
        Trie *t = new Trie();
        TrieNode *root = t->root;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                buildTrie(root, board, i, j, m, n);
            }
        }
        for (int i = 0; i < words.size(); i ++) {
            if (t->findWord(words[i])) res.push_back(words[i]);
            
        }
        return res;
    }
};
*/
