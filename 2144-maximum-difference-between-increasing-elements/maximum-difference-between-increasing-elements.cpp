class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        multiset<int , greater<>> ms;
        for(auto &i : nums){
            ms.insert(i);
        }
        int ans = -1;
        for(int i = 0; i < nums.size() ; i++){
            ms.erase( ms.find(nums[i]) );
            auto it = *ms.begin();
            if( it > nums[i] ){
                ans = max(ans, it - nums[i]);
            }
        }
        return ans;
    }
};