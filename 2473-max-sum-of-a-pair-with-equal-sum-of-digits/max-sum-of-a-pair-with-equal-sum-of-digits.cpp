class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        vector freq(9 * 10, -1);
        int size = nums.size();
        int res = -1;
        for (int i = 0; i < size; i++) {
            
            if( freq[sumOfDigits(nums[i])] != -1 ){
                res = max(res, nums[i] + freq[sumOfDigits(nums[i])]);
            }
            freq[sumOfDigits(nums[i])] = max(freq[sumOfDigits(nums[i])], nums[i]);
        }
        return res;
    }
};