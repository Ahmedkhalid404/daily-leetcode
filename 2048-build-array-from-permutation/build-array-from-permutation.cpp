class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = int(nums.size());
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[ i ] = nums[ nums[i] ]; 
        }

        return ans;
    }
};