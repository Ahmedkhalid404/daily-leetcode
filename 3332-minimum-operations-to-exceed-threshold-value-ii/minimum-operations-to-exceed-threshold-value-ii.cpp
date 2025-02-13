class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq(begin(nums), end(nums));
        int res = 0;
        while( pq.top() < k ){
            int64_t x = pq.top(); pq.pop();
            int64_t y = pq.top(); pq.pop();
            pq.push( x * 2LL + y );
            res++;
        }
        
        return res;
    }
};