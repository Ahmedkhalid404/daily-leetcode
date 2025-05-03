class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = 1e5;
       for(int i = 1; i <= 6; i++){

            for(int j = 1; j <= 2; j++){

                int cnt = 0;
                bool flag = true;
                for(int k = 0; k < tops.size(); k++){

                    if( j == 1 ){ // try top

                        if( tops[ k ] != i ){
                            
                            if( bottoms[ k ] != i ){
                                flag = false;
                                break;
                            }
                            //swap

                            cnt ++;
                        }

                    } else{ // j = 2 -> try bottom

                        if( bottoms[ k ] != i ){

                            if( tops[ k ] != i ){
                                flag = false;
                                break;
                            }

                            cnt ++;

                        }

                    }

                }
                if( flag ){
                    ans = min(ans, cnt);
                }


            }

       }

       if(ans == 1e5)
            return -1;
        
        return ans;

    }
};