class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (p->next[c - 'a'] == NULL) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, 0, root);
    }
    
    bool query(string word, int pos, TrieNode* p) {
        for (int i = pos; i < word.size(); i ++) {
            char c = word[i];
            if (c != '.') {
                if (p->next[c - 'a'] == NULL) return false;
                else p = p->next[c - 'a'];
            } else {
                for (int j = 0; j < 26; j ++) {
                    if (p->next[j] != NULL) {
                        if (query(word, i + 1, p->next[j]))
                            return true;
                    }
                }
                return false;
            }
        }
        if (p->is_word) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
