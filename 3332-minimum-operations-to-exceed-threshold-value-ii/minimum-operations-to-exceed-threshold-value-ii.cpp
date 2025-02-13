class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<int64_t> st;
        for(auto &it : nums) st.insert(it);

        int res = 0;
        while( (st.size() > 1) and (*st.begin() < k) ){
            int64_t x = *st.begin(); st.erase(st.begin());
            int64_t y = *st.begin(); st.erase(st.begin());
            st.insert( x * 2LL + y );
            res++;
        }
        
        return res;
    }
};