class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int const n = nums.size();
        int freq[101] = {};

        int i = n - 1;
        for(; ~i ; i--){
            if( freq[nums[i]] ){
                i ++;
                break;
            }
            freq[nums[i]] ++;
        }

        if( i == -1 ) return 0;

        return i / 3 + (i % 3 != 0);

    }
};