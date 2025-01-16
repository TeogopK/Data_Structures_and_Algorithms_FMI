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
public:
    Trie() : root(new TrieNode()) { }
    
    void insert(string word) {
        TrieNode* iter = root;
        for(char ch: word) {
            if(!iter->containsKey(ch)) {
                iter->setKey(ch, new TrieNode());
            }
            iter = iter->getKey(ch);
        }
        iter->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* iter = root;
        for(char ch: word) {
            if(!iter->containsKey(ch)) {
                return false;
            }
            iter = iter->getKey(ch);
        }
        return iter->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* iter = root;
        for(char ch: prefix) {
            if(!iter->containsKey(ch)) {
                return false;
            }
            iter = iter->getKey(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
