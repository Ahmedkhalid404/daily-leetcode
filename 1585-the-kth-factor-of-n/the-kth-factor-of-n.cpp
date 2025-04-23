class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;factors.reserve(n);
        for(int i = 1; i * i <= n ; i++){
            if( n % i == 0 ){
                factors.push_back(i);
                if(i != (n / i)) factors.push_back(n / i);
            }
        }

        ranges::sort(factors);

        return k > factors.size() ? -1 : factors[k - 1];

    }
};