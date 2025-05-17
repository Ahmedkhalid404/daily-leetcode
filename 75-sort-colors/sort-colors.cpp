class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[4] = {};
        freq[3] = -404;
        int n = int(nums.size());

        for(int i = 0; i < n; i ++){
            freq[nums[i]] ++;
        }

        int val = 0;
        while( !freq[val] ) val ++;

        for(int i = 0; i < n; i ++){
            nums[i] = val;
            freq[val] --;
            while( !freq[val] ) val ++;
        }

    }
};