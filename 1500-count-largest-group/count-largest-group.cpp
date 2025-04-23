class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;
        int mx = 0,cnt = 0;
        for(int i = 1; i <= n; i++){
            int temp = i;
            int sum = 0;
            while( temp ){
                sum += temp % 10;
                temp /= 10;
            }
            freq[sum] ++;
            if(freq[sum] > mx){
                mx = freq[sum];
                cnt = 1;
            } else if(freq[sum] == mx){
                cnt ++;
            }
        }
        return cnt;
    }
};