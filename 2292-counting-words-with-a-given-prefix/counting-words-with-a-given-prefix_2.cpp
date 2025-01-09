class Solution {
private:
    class Trie{
        private:
            struct node{
                node *nxt[ int( 'z' - 'a' + 1 ) ]{};
                int cnt , end;

                explicit node(){
                    memset( nxt , 0 , sizeof nxt);
                    cnt = end = 0;
                }
            }*root;

            static void insert(node *trie ,string &s){
                for(auto &ch : s){
                    int idx = int(ch - 'a');
                    if( trie->nxt[ idx ] == nullptr ){
                        trie->nxt[ idx ] = new node;
                    }
                    trie = trie->nxt[ idx ];
                    trie->cnt++;
                }
                trie->end++;
            }

            static bool isFound(node *trie,string &s){
                for(auto &ch : s){
                    int idx = int(ch - 'a');
                    if( trie->nxt[ idx ] == nullptr ){
                        return false;
                    }
                    trie = trie->nxt[ idx ];
                }
                return ( trie->end > 0 );
            }
            static int getPrefix(node *trie,string &s){
                for(auto &ch : s){
                    int idx = int(ch - 'a');
                    if( trie->nxt[ idx ] == nullptr ){
                        return 0;
                    }
                    trie = trie->nxt[ idx ];
                }
                return trie->cnt;
            }

        public:
            explicit Trie(){
                root = new node;
            }
            void insert(string &s){
                insert( root , s );
            }
            bool isFound(string &s){
                return isFound(root , s);
            }
            int getPrefix(string &s){
                return getPrefix(root,s);
            }

        };
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(auto &it : words) trie.insert(it);

        return trie.getPrefix(pref);
    }
};
