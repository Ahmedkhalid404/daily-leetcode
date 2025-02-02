class Solution {
public:
    bool check(vector<int>& nums) {
        int mn = 0;
        bool flag = false;
        for (int i = 1; i < nums.size(); ++i) {
            if( (nums[i] != nums[mn]) ){
                flag = true;
            }

            if( !flag ){
                if( nums[i] < nums[mn] )
                    mn = i;
            }
            else{
                if( nums[i] <= nums[mn] )
                    mn = i, flag = false;
            }
        }

        int prev = nums[mn];
        for (int i = mn; i < nums.size(); ++i) {
            if( nums[i] < prev )
                return false;
            prev = nums[i];
        }
        for (int i = 0; i < mn; ++i) {
            if( nums[i] < prev )
                return false;
            prev = nums[i];
        }

        return true;
    }
};