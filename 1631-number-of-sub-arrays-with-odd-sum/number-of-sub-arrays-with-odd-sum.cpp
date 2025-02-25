class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = int(arr.size());
        int even = 0;
        int odd  = 0;
        int64_t sum = 0;
        for(int i = 0; i < n ; i ++){
            sum = sum + arr[i];
            (sum & 1 ? odd : even) ++;
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            ans += odd;
            if(arr[i] & 1){
                odd --;
                swap(odd, even);
            }
            else{
                even--;
            }
            if(ans >= 1e9 + 7) ans -= 1e9 + 7;
        }
        return ans;
    }
};