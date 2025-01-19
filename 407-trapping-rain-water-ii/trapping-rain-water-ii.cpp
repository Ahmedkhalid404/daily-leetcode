class Solution {
private:
    template<class T> using min_pq = priority_queue< T, vector <T>, greater<> >;
    vector<int> dx = { 1 , -1 , 0 , 0 },
            dy = { 0 , 0 , 1 , -1 };

public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int n = int(heightMap.size());
        int m = int(heightMap[0].size());
        int vol = 0;

        vector vis(n, vector(m, false));
        min_pq<pair<int, pair<int, int>>> pq;


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if( (i == 0) or (i == (n - 1)) or (j == 0) or (j == (m - 1)))
                    pq.push({heightMap[i][j], {i,j}}), vis[i][j] = true;
            }
        }


        auto isValid = [&](int i,int j,int k) {
            int new_i = i + dy[ k ];
            int new_j = j + dx[ k ];

            return(
                    ( ( new_i < n ) && ( new_i > -1) ) &&
                    ( ( new_j < m ) && ( new_j > -1 ) ) &&
                    ( !vis[ new_i ][ new_j ] )
             );
        };

        int minBdHt = 0;

        while( !pq.empty() ){

            int currHt = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();

            minBdHt = max(minBdHt, currHt);

            for (int k = 0; k < 4; ++k) {

                if( isValid(i, j, k) ){

                    int new_i = i + dy[ k ];
                    int new_j = j + dx[ k ];

                    pq.push({heightMap[new_i][new_j], {new_i,new_j}}), vis[new_i][new_j] = true;

                    if( heightMap[new_i][new_j] < minBdHt ){
                        vol += minBdHt - heightMap[new_i][new_j];
                    }
                }

            }


        }
        
        return vol;
    }
};
