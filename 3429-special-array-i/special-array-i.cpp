class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool prev = nums[0] & 1;
        int sz = int(nums.size());
        for(int i = 1; i < sz; i ++){
            if( prev == (nums[i] & 1) )
                return false;
            prev = !prev; 
        }
        return true;
    }
};