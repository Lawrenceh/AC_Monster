/* NOTE: dp solution, see Problem 139 similar idea */

struct TrieNode;

// Allocate node on stack instead of heap. The pool size is
// just tuned by hand to avoid MLE for this question only.
TrieNode* pool[54000][26];

struct TrieNode{
    TrieNode(int identity) : idx(identity) {
        // Reset to NULL because the pool might be polluted by the last run.
        memset(pool[idx], 0, sizeof(pool[idx]));
        children = pool[idx];
    }    
    int idx;
    bool isWord = false;
    TrieNode** children = nullptr;
};

class Trie {
public:
    Trie() : root(new TrieNode(identity++)) {}

    void insert(TrieNode* root, string& word) {
        auto node = root;
        for(char c: word) {
            if(node->children[c - 'a'] == nullptr) {
                TrieNode* newNode = new TrieNode(identity++);
                node->children[c - 'a'] = newNode;
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
private:
    int identity = 0;
    
public:
    TrieNode* root = nullptr;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        
        Trie trie;
        for(auto& word: words) {
            if(dfs(trie.root, word, 0, trie.root, 0)) result.push_back(word);
            else trie.insert(trie.root, word);
        }
        return result;
    }
    
private:
    bool dfs(TrieNode* root, string& word, int pos, TrieNode* node, int num_words) {
        if(pos == word.size()) {
            if(node->isWord && num_words > 0) return true;
            else return false;
        }
        
        if(node->children[word[pos] - 'a'] == nullptr) return false;
        auto next = node->children[word[pos] - 'a'];
        if(next->isWord) {
            if(dfs(root, word, pos + 1, root, num_words + 1)) return true;
        }
        if(dfs(root, word, pos + 1, next, num_words)) return true;
        else return false;
    }
};

/* MLE solution

class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;
    
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

void insert(string word, TrieNode *root) {
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i ++) {
        if (p->next[word[i] - 'a'] == NULL) {
            p->next[word[i] - 'a'] = new TrieNode();
        }
        p = p->next[word[i] - 'a'];
    }
    p->is_word = true;
}

class Solution {
public:
    bool findWord(TrieNode *root, string s, int pos, int cnt) {
        TrieNode *p = root;
        for (int i = pos; i < s.size(); i ++) {
            if (p->next[s[i] - 'a'] == NULL) return false;
            if (p->next[s[i] - 'a']->is_word) {
                if (i == s.size() - 1) return cnt >= 1;
                if (findWord(root, s, i + 1, cnt + 1)) {
                    return true;
                }
            }
            p = p->next[s[i] - 'a'];
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        if (words.empty()) return res;
        TrieNode *root = new TrieNode();
        for (auto w: words) {
            insert(w, root);
        }
        for (auto w: words) {
            if (findWord(root, w, 0, 0)) {
                res.push_back(w);
            }
        }
        return res;
    }
};

*/
