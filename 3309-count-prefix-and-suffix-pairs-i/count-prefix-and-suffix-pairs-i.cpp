class Solution {
private:
    bool isPrefixAndSuffix(string &s, string &t){

        if( s.size() > t.size() )
                return false;
        int sz = int(s.size());

        int i = 0, j1 = sz - 1, j2 = int(t.size() - 1);
        while( i < sz ){

                if( s[i] != t[i] )
                        return false;

                if( s[j1] != t[j2] )
                        return false;

                i++, j1--, j2--;

        }

        return true;

    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int sz = int(words.size());
        for(int i = 0; i < sz; i++){

                for(int j = i + 1; j < sz; j++){
                        cnt += isPrefixAndSuffix(words[i], words[j]);
                }

        }

        return cnt;
    }
};