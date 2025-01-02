class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int size = int(words.size());
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        vector< int > pref(size);
        for (int i = 0; i < size; ++i) {
            pref[ i ] = vowels.contains(words[ i ].front()) and vowels.contains(words[ i ].back());
            if( i ) pref[ i ] += pref[ i - 1 ];
        }

        vector< int > res;res.reserve(queries.size());
        for(auto range : queries){
            auto [l, r] = make_pair(range[0], range[1]);
            res.push_back( pref[ r ] - (l ? pref[ l - 1 ] : 0) );
        }
        return res;
    }
};
