class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

    unordered_set<int> st;

    for(auto it : nums){
        bitset<20> bt(it);
        st.insert(bt.to_ullong());
    }
    int i = 0;
    while( -404 ){
        if(!st.contains(i)){
            bitset<20> bt(i);
            string res = ""s;
            for(int j = 0; j < nums.size(); j ++){
                res.push_back(char(bt[j] + '0'));
            }
            reverse(res.begin(), res.end());
            return res;
        }
        i++;
    }
    assert(false);
    return ""s;
}
};