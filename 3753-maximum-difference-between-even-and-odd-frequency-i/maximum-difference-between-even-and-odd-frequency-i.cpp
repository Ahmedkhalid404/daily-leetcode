class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {};
        int maxOdd = 0;
        int mnEven = 1e9;
        for(auto &ch : s){
            freq[ch - 'a'] ++;
        }
        for(int i = 0; i < 26; i++){
            int f = freq[i];
            if(!f) continue;
            if ( f & 1 ){
                maxOdd = max(maxOdd, f);
            } else {
                mnEven = min(mnEven, f);
            }
        }

        return maxOdd - mnEven;
    }
};