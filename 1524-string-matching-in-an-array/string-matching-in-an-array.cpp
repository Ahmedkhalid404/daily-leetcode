class Solution {
private:

class SuffixTrie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        int cnt;
        TrieNode() : isEndOfWord(false), cnt(0) {}
    };

    TrieNode* root;

public:
    SuffixTrie() {
        root = new TrieNode();
    }

    ~SuffixTrie() {
        clear(root);
    }

    void insert(const string& word) {
        for (int i = 0; i < word.size(); ++i) {
            TrieNode* current = root;
            for (int j = i; j < word.size(); ++j) {
                char ch = word[j];
                if (!current->children.count(ch)) {
                    current->children[ch] = new TrieNode();
                }
                current = current->children[ch];
                current->cnt ++;
            }
            current->isEndOfWord = true;
        }
    }
    
    // don't check if word is exist or not
    void remove(const string &word){
        int size = int(word.size());
        for (int i = 0; i < size; ++i) {
            TrieNode *current = root;
            for (int j = i; j < size; ++j) {
                current = current->children[word[j]];
                current->cnt --;
            }
            
        }
    }

    bool search(const string& substring) {
        TrieNode* current = root;
        for (char ch : substring) {
            if (!current->children.count(ch)) {
                return false;
            }
            current = current->children[ch];
            if( current->cnt < 1 ){
                return false;
            }
        }
        return true;
    }

private:
    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }
};

public:
    vector<string> stringMatching(vector<string>& words) {
        SuffixTrie trie;
        
        for(auto &word : words){
            trie.insert(word);
        }

        vector< string > ans;ans.reserve(words.size());
        for(auto &word : words){
            trie.remove(word);

            if( trie.search( word ) ){
                ans.push_back(word);
            }

            trie.insert(word);
        }

        return ans;
        
    }
};