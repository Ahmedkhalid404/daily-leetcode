class Solution {
public:
    string smallestNumber(string pattern) {
        int const n = pattern.size() + 1;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        
        do{
            bool flag = true;
            string res = ""s;
            for(int i = 0; i < n - 1 ; i ++){
                if( pattern[i] == 'I' ) if(nums[i] > nums[i + 1]) flag = false;
                if(pattern[i] == 'D') if(nums[i] < nums[i + 1]) flag = false;
            }
            if(flag){
                for(int i = 0; i < n; i++) res.push_back(char(nums[i] + '0'));
                return res;
            }
        }while(next_permutation(nums.begin(), nums.end()));
        return ""s;
    }
};