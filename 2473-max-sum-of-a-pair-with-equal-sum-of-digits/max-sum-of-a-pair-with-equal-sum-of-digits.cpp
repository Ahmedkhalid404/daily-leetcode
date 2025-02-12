class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        int size = nums.size();
        auto sumOfDigits = [&](int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        int res = -1;
        for (int i = 0; i < size; i++) {
            
            if( freq[sumOfDigits(nums[i])] ){
                res = max(res, nums[i] + freq[sumOfDigits(nums[i])]);
            }
            freq[sumOfDigits(nums[i])] = max(freq[sumOfDigits(nums[i])], nums[i]);
        }
        return res;
    }
};