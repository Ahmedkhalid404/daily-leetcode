class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> shifts) {
        int size = int(s.size());
        vector< int > partial[2];
        partial[1].resize( size + 1 ); // pos
        partial[0].resize( size + 1 ); // neg

        for(auto query : shifts){
            int l = query[0];
            int r = query[1];
            int dir = query[2];

            partial[ dir ][ l ] += 1;
            partial[ dir ][ r + 1 ] -= 1;
        }

        for(int i = 1; i < size ; i ++){

            for(int j = 0; j < 2 ; j ++){

                partial[ j ][ i ] += partial[ j ][ i - 1 ];

            }

        }


        for(int i = 0; i < size ; i ++){

            for(int j = 0; j < 2; j ++){

                partial[ j ][ i ] %= 26;

            }


            // pos
            while( partial[ 1 ][ i ] --> 0 ) {

                if( s[i] == 'z' ){
                    s[i] = 'a';
                }
                else{
                    s[i]++;
                }

            }


            while( partial[ 0 ][ i ] --> 0 ){

                if( s[i] == 'a' ){

                    s[i] = 'z';

                }

                else{

                    s[i] --;

                }

            }

            

        }
        return s;
    }
};
