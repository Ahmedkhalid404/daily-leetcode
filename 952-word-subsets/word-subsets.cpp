class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        unordered_map<char, int> mx_freq, freq;
        for(auto &word : words2){
            freq.clear();
            for(auto &ch : word){
                mx_freq[ch] = max(mx_freq[ch], ++freq[ch]);
            }
        }

        vector< string > res;res.reserve(words1.size());
        for(auto &word : words1){
            freq.clear();
            for(auto &ch : word){
                freq[ch]++;
            }
            for(auto &[k, v] : mx_freq){
                if( v > freq[ k ] )
                    goto jump;
            }
            res.push_back( word );
            jump:;
        }

        return res;

    }
};