class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int ans = 0;
        map< pair<int, int> , int > freq;
        for(int i = 0; i < n; i++){
            ans = ans + freq[ {min(dominoes[i][0],dominoes[i][1]),max(dominoes[i][0],dominoes[i][1]) } ];
            freq[ {min(dominoes[i][0],dominoes[i][1]),max(dominoes[i][0],dominoes[i][1]) } ]++;
        }
        return ans;
    }
};