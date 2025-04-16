class Solution {
private:
    long long countPairs(int n) { return n * (n - 1LL) / 2; }
public:
    long long countGood(vector<int> nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = -1;
        int cnt = 0;
        int64_t ans = 0;

        unordered_map<int, int> freq;

        while ((r + 1) < n) {
            r++;

            freq[nums[r]]++;
            if (freq[nums[r]] >= 2) {
                cnt = cnt - countPairs(freq[nums[r]] - 1) +
                      countPairs(freq[nums[r]]);
            }

            while (cnt >= k) {
                ans = ans + (n - r);

                freq[nums[l]]--;
                if (freq[nums[l]]) {
                    cnt = cnt - countPairs(freq[nums[l]] + 1) +
                          countPairs(freq[nums[l]]);
                }

                l++;
            }
        }

        return ans;
    }
};