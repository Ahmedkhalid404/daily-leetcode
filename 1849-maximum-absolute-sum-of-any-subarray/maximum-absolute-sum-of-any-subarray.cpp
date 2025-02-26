class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = nums[0], currentMaxSum = 0;
        int minSum  = nums[0], currentMinSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // max sum
            if (currentMaxSum <= 0) {
                currentMaxSum = nums[i];
            } else {
                currentMaxSum += nums[i];
            }
            if (currentMaxSum > maxSum) {
                maxSum = currentMaxSum;
            }

            // min sum
            if(currentMinSum >= 0){
                currentMinSum = nums[i];
            } else{
                currentMinSum += nums[i];
            }
            if(currentMinSum < minSum){
                minSum = currentMinSum;
            }

        }

        return max(maxSum, abs(minSum));
    }
};