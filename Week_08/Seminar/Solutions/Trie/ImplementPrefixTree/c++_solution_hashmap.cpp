struct TrieNode {
    // може и vector
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;

    // Optional:
    int count = 0; // брой думи с този префикс
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        auto iter = root;
        for (char ch : word) {
            if (iter->children.find(ch) == iter->children.end()) {
                iter->children[ch] = new TrieNode();
            }
            iter = iter->children[ch];
        }
        iter->isEndOfWord = true;
    }

    TrieNode* searchPrefix(const std::string& word) {
        auto iter = root;
        for (char ch : word) {
            if (iter->children.find(ch) == iter->children.end()) {
                return nullptr;
            }
            iter = iter->children[ch];
        }

        return iter;
    }

    bool search(const std::string& word) {
        auto node = searchPrefix(word);
        return node && node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        return searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */