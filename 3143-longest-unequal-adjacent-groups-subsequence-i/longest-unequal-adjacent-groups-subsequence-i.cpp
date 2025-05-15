class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = int(words.size());
        vector<string> res;res.reserve(n);
        for(int i = 0; i < n ; i ++){
                vector<string> curr;curr.reserve(n);
                curr.push_back(words[i]);
                for(int j = i + 1; j < n ; j ++ ){
                    if( groups[j] == groups[j - 1] ) continue;
                    if( words[j] == words[j - 1] ) continue;

                    curr.push_back(words[j]);
                }
                if( curr.size() > res.size() )
                    res = curr;
        }
        return res;
    }
};