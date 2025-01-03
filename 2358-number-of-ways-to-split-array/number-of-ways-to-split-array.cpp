class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int64_t sumLeft = 0;
        int64_t sumRight = accumulate(nums.begin(), nums.end(), 0LL);
        int size = int(nums.size());
        int ans = 0;

        for (int i = 0; i < size - 1; ++i) {
            sumLeft = sumLeft + nums[ i ];
            sumRight = sumRight - nums[ i ];
                        
            ans += sumLeft >= sumRight;
        }
        
        return ans;
    }
};