struct TrieNode {
    //char ch;
    //TrieNode* children[26];
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* iter = root;
        for(size_t i = 0; i < word.size(); i++) {
            if(!iter->children.count(word[i])) {
                iter->children[word[i]] = new TrieNode();
            }
            iter = iter->children[word[i]];
        }
        iter->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* iter = root;
        for(size_t i = 0; i < word.size(); i++) {
            if(!iter->children.count(word[i])) {
                return false;
            }
            iter = iter->children[word[i]];
        }
        return iter->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* iter = root;
        for(size_t i = 0; i < prefix.size(); i++) {
            if(!iter->children.count(prefix[i])) {
                return false;
            }
            iter = iter->children[prefix[i]];
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
