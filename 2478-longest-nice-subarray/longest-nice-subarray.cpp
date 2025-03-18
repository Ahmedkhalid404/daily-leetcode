class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int const n = nums.size();

        int ans = 1;

        for (int i = 0; i < n; i++) {

            int r = i - 1;

            for (int j = i + 1; j < n; j++) {

                for (int k = j - 1; k >= i ; k--) {
                    if ( nums[j] & nums[k] ) goto jump;
                }
                r = j;
                //cout << nums[i] << ' ' << nums[j] << '\n'; 

            }

            jump:;

            ans = max(ans, r - i + 1);
        }

        return ans;
    }
};
