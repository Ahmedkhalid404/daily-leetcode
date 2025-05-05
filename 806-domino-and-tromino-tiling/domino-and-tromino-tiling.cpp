class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        deque<int> seq = {1, 2, 5};
        if (n <= seq.size())
            return seq[n - 1];

        n -= 3;

        int res;

        while (n-- > 0) {
            res = ((((seq.back() % mod) * 2) % mod) + (seq[seq.size() - 3] % mod)) % mod;
            seq.pop_front();
            seq.push_back(res);
        }
        return res;
    }
};