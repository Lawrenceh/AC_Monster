/* Trie */
class TrieNode {
public:
    TrieNode *next[26];
    bool isPrefix;
    string word;
    TrieNode () {
        for (int i = 0; i < 26; i ++) next[i] = nullptr;
        isPrefix = false;
    }
};

class Trie {
public:
    TrieNode *root = new TrieNode();
    void insert(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (p->next[c - 'a'] == nullptr) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->word = word;
        p->isPrefix = true;
    }
    string find(string word) {
        TrieNode *p = root;
        for (auto c: word) {
            if (p->next[c - 'a'] == nullptr) return "";
            p = p->next[c - 'a'];
            if (p->isPrefix) return p->word;
        }
        return "";
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        // build Trie
        Trie *t = new Trie();
        for (auto w: dict) {
            t->insert(w);
        }
        // parse sentence
        istringstream in(sentence);
        ostringstream out;
        string word;
        string s;
        while (in >> word) {
            s = t->find(word);
            if (s == "") out << word << " ";
            else out << s << " ";
        }
        s = out.str();
        s.pop_back();
        return s;
    }
};
