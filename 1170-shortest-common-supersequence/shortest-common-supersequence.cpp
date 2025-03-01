class Solution {
    public:
        string shortestCommonSupersequence(string s, string t) {
            
            // longest common subseq
            int n = int(s.size());
            int m = int(t.size());
    
            vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
    
            for(int i = n - 1; ~i ; i --){
                for(int j = m - 1; ~j ; j --){
                    dp[i][j] = max({
                        dp[i + 1][j],
                        dp[i][j + 1],
                        dp[i + 1][j + 1] + (s[i] == t[j]),
                    });
                }
            }
    
            vector<pair<int,int>> idx_longest_sub_seq;
            idx_longest_sub_seq.reserve(min(n,m));
    
            int i = 0, j = 0;
            while( dp[i][j] ){
                int mx = max({
                    dp[i + 1][j],
                    dp[i][j + 1],
                    dp[i + 1][j + 1]
                });
                if( mx == dp[i + 1][j + 1] ) {
                    if(s[i] == t[j]){ 
                        idx_longest_sub_seq.push_back({i,j});
                    }
                    i ++, j ++;
                }
                else if( mx == dp[i][j + 1] ) j ++;
                else i++;
            }
            
            i = 0; j = 0;
            string res = ""s;
            for(int l = 0; l < idx_longest_sub_seq.size(); l++){

                while(i < idx_longest_sub_seq[l].first){
                    res.push_back(s[i ++]);
                }

                while(j < idx_longest_sub_seq[l].second){
                    res.push_back(t[j ++]);
                }

                res.push_back(s[i]);
                i++, j++;
            }

            while(i < n){
                res.push_back(s[i ++]);
            }
            while(j < m){
                res.push_back(t[j ++]);
            }

            return res;
        }
    };
