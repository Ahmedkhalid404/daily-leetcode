class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        int n = int(g.size());
        int m = int(g[0].size());

        int a = pow(-2, 31), b = pow(2, 31) - 1;

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(a, b);


        int notValue = distrib(gen);
        bool flag = false;
        while( !flag ){
            flag = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] == notValue){
                        flag = false;
                        goto jump;
                    }
                }
            }
            jump:;
        }

        cout << notValue << '\n';
        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if( !g[i][j] ){

                    for(int k = 0; k < m; k++){ // row
                        if( g[i][k] ) g[i][k] = notValue;
                    }

                    for(int k = 0; k < n; k ++){
                        if(g[k][j]) g[k][j] = notValue;
                    }

                }

            }

        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == notValue) g[i][j] = 0;
            }
        }

    }
};