class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freqArray, freqCurr;
        for (auto it : nums)
            freqArray[it]++;

        int n = int(nums.size());
        int l = 0, r = -1;
        int ans = 0;

        while ((r + 1) < n) {

            freqCurr[nums[++r]]++;

            while (freqCurr.size() == freqArray.size()) {
                ans += n - r;
                freqCurr[nums[l]]--;
                if (freqCurr[nums[l]] < 1) {
                    freqCurr.erase(nums[l]);
                }
                l++;
            }
        }

        return ans;
    }
};