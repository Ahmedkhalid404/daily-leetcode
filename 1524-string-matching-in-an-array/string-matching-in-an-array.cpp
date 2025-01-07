class Solution {
private:

class SuffixTrie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
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
            }
            current->isEndOfWord = true;
        }
    }

    bool search(const string& substring) {
        TrieNode* current = root;
        for (char ch : substring) {
            if (!current->children.count(ch)) {
                return false;
            }
            current = current->children[ch];
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
        
        sort(words.begin(), words.end(), [&](auto a, auto b){
           return a.size() > b.size(); 
        });

        vector< string > ans; ans.reserve(int(words.size()));

        for(auto &word : words){
            if( trie.search(word) )
                ans.push_back(word);

            trie.insert(word);
        }

        return ans;
        
    }
};