class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = int(nums.size());
        unordered_set<string> st;
        int freq[ n ][2];
        for(int i = 0; i < n ; i ++){
            st.insert(nums[i]);
            for(int j = 0; j < 2; j ++){
                freq[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i ++){
            
            for(int j = 0; j < n; j ++){
                freq[ j ][ nums[i][j] - '0' ] ++;
            }

        }

        string res = ""s;
        for(int i = 0; i < n; i ++){
            if( freq[i][0] < freq[i][1] )
                res.push_back('0');
            else
                res.push_back('1');
        }

        for(int i = 0; i < n; i++){
            if(!st.contains(res)){
                return res;
            }

            if(res[i] == '0') res[i] = '1';
            else res[i] = '0';
        }

        return ""s;
    
    }
};