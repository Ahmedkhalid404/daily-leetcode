class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = int(amount.size());
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < edges.size(); i ++){
            graph[ edges[i][0] ].push_back(edges[i][1]);
            graph[ edges[i][1] ].push_back(edges[i][0]);
        }
        
        vector<int> levels(n);
        vector<int> bob_moves(n);

        function<void(int, int)> get_levels = [&](int node, int lvl){
            levels[node] = lvl;
            for(auto neg : graph[node]){
                if(!levels[neg])
                    get_levels(neg, lvl + 1);
            }

        };


        function<void(int, int)> get_bob_path = [&](int node, int time){
            bob_moves[node] = time;
            for(auto neg : graph[node]){
                if(levels[neg] < levels[node])
                    get_bob_path(neg, time + 1);
            }

        };

        function<int(int, int)> get_mx_income_to_alice = [&](int node, int time){
            int val = bob_moves[node] == 0    ? amount[node] :
                      bob_moves[node] == time ? amount[node] / 2:
                      bob_moves[node] < time  ? 0               :
                      amount[node];

            if(graph[node].size() == 1 and node != 0){
                return val;
            }


            int mx = -1e9;
            for(auto neg : graph[node]){
                if(levels[neg] > levels[node]){
                    mx = max(mx, get_mx_income_to_alice(neg, time + 1) + val);
                }
            }

            return mx;
        };

        
        return get_levels(0, 1) , get_bob_path(bob, 1) , get_mx_income_to_alice(0, 1);
    }
};

