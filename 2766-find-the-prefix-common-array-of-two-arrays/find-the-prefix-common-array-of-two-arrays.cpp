class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int res = 0;
        int n = int(A.size());
        vector<int> ans;ans.reserve(n);
        int freqA[ n + 1 ], freqB[ n + 1 ];

        fill(freqA, freqA + n + 1, 0);
        fill(freqB, freqB + n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if( A[i] == B[i] ) res ++;
            
            if( freqB[ A[i] ] ) res ++;
            if( freqA[ B[i] ] ) res ++;
            
            freqA[ A[i] ] ++;
            freqB[ B[i] ] ++;
            
            ans.push_back( res );
        }
        
        return ans;
    }
};