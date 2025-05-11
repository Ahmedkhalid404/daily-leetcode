class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = int(arr.size());
        for(int i = 0; i < n - 2 ; i ++){
            if( (arr[i] & 1) and (arr[i + 1] & 1) && (arr[i + 2] & 1) )
                return true;
        }
        return false;
    }
};