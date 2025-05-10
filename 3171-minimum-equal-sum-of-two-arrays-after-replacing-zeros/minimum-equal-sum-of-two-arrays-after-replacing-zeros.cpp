class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int64_t sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (auto it : nums1) {
            sum1 = sum1 + it;
            if (!it)
                zeros1++;
        }
        for (auto it : nums2) {
            sum2 = sum2 + it;
            if (!it)
                zeros2++;
        }


        if ( (sum1 + zeros1) == (sum2 + zeros2) )
            return sum1 + zeros1;

        if ( 
                (zeros1 == 0 and zeros2 == 0) or
                (zeros1 == 0 and (sum2 + zeros2) > sum1) or
                (zeros2 == 0 and (sum1 + zeros1) > sum2) 
            ) {
            return -1;
        }

        return max(sum1 + zeros1, sum2 + zeros2);
    }
};
