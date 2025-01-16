struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() : root(new TrieNode())  { }
    
    void addWord(string word) {
        TrieNode* iter = root;
        for (char ch : word) {
            if (!iter->children.count(ch)) {
                iter->children[ch] = new TrieNode();
            }
            iter = iter->children[ch];
        }
        iter->isEndOfWord = true;
    }
    
    bool searchUtil(std::string_view word, TrieNode* root) {
        TrieNode* iter = root;
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                for (auto& kvp : iter->children) {
                    if (searchUtil(word.substr(i + 1), kvp.second)) {
                        return true;
                    }
                }
                return false;
            }
            if (!iter->children.count(word[i])) {
                return false;
            }
            iter = iter->children[word[i]];
        }
        return iter->isEndOfWord;
    }

    bool search(string word) {
        return searchUtil(std::string_view(word), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
