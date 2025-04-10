class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        if( nums.front() < k ) return -1;

        int ans = 0;
        int idx = nums.size() - 2;
        while( idx > -1 ){
            if(nums[idx] != nums[idx + 1])
                ans ++;
            idx --;
        }
        return ans + (nums.front() != k);
    }
};