class TrieNode {
private:
    TrieNode* children[26]{};
public:
    bool isEndOfWord = false;

    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    TrieNode* getKey(char ch) const {
        return children[ch - 'a'];
    }
    void setKey(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }
};

class Trie {
    TrieNode* root;

    TrieNode* searchEndNode(const string& word) const {
        TrieNode* iter = root;
        for (char ch : word) {
            if (!iter->containsKey(ch)) {
                return nullptr;
            }
            iter = iter->getKey(ch);
        }
        return iter;
    }
public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* iter = root;
        for (char ch : word) {
            if (!iter->containsKey(ch)) {
                iter->setKey(ch, new TrieNode());
            }
            iter = iter->getKey(ch);
        }
        iter->isEndOfWord = true;
    }

    bool search(const string& word) const {
        auto node = searchEndNode(word);
        return node && node->isEndOfWord;
    }

    bool startsWith(const string& prefix) const {
        return searchEndNode(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */