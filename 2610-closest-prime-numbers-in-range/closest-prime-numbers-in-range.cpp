vector<int> primes = []() {
    const int N = 1e6;
    bitset<N> sieve; sieve.set();
    sieve[0] = sieve[1] = false;
    vector<int> pr; pr.reserve(5761455);
    for(int i = 2; i < N; i = (int)sieve._Find_next(i)) {
        pr.push_back(i);
        if(i * 1LL * i >= N) continue;
        for(int j = i * i; j < N; j += i)
            sieve[j] = false;
    }
    return pr;
}();

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int idx1 = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        int idx2 = upper_bound(primes.begin(), primes.end(), right) - primes.begin();

        vector<int> res = {-1,-1};
        for(int i = idx1; i < idx2 - 1; i++){
            if( primes[i] >= left && primes[i + 1] <= right ){
                if(res[0] == -1){
                    res = {primes[i], primes[i + 1]};
                }
                else if( (primes[i + 1] - primes[i]) < (res[1] - res[0]) ){
                    res = {primes[i], primes[i + 1]};
                }
            }
        }
        

        return res;
    }
};