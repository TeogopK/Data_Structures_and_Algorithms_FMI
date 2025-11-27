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
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* iter = root;
        for (char ch : word) {
            if (!iter->containsKey(ch)) {
                iter->setKey(ch, new TrieNode());
            }
            iter = iter->getKey(ch);
        }
        iter->isEndOfWord = true;
    }
};


class Solution {
    void gatherDfs(TrieNode* curr, vector<string>& result, string& word) {
        if (!curr) {
            result.push_back(word);
            return;
        }
        if (curr->isEndOfWord) {
            result.push_back(word);
        }
        if (result.size() == 3) {
            return;
        }
        for (auto ch = 'a'; ch <= 'z'; ch++) {
            if (curr->containsKey(ch)) {
                word += ch;
                gatherDfs(curr->getKey(ch), result, word);
                word.pop_back();
                if (result.size() == 3) {
                    return;
                }
            }
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size(), vector<string>());
        Trie trie;
        for (auto& p : products) {
            trie.insert(p);
        }
        string prefix = "";
        auto node = trie.root;
        for (size_t i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            node = node->getKey(searchWord[i]);
            if (!node) {
                break;
            }
            vector<string> resultInner;
            gatherDfs(node, resultInner, prefix);
            result[i] = std::move(resultInner);
        }

        return result;
    }
};