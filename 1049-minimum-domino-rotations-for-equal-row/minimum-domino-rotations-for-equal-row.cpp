class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = 1e5;
        for(int i = 1; i <= 6; i++){


            for(int j = 1; j <= 2; j++){

                int cnt = 0;
                for(int k = 0; k < tops.size(); k++){
                    auto &curr = (j == 1 ? tops : bottoms);
                    auto &other = (j == 1 ? bottoms : tops);
                    if( curr[k] != i ){

                        if( other[k] != i ){
                            goto jump;
                        }

                        cnt ++;

                    }
                }

                ans = min(ans, cnt);

            }

            jump:;


        }

        return ans == 1e5 ? -1 : ans;

    }
};