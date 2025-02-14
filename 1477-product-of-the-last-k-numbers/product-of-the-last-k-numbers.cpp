class ProductOfNumbers {
private:
    // Our problem lies in the fact that the numbers start from 0;
    // otherwise, it would have been a straightforward prefix multiplication.
    // As a workaround, we will treat zeros as ones and create another prefix array
    // that counts the zeros in a given range. We will compute the multiplication 
    // as if there were no zeros, and using the prefix that counts the number of zeros,
    // we can determine if there is at least one zero in the required range.
    // If so, the result for that range will be zero.
    vector<int> pref_zeros, pref_mul;
    const int MAX_N = 4 * 1e4;
public:
    ProductOfNumbers() {
        pref_zeros.reserve(MAX_N);
        pref_mul.reserve(MAX_N);

        // will use 1-based indexing
        pref_zeros.push_back(0);
        pref_mul.push_back(1);
    }
    
    void add(int num) {
        pref_zeros.push_back(pref_zeros.back() + (num == 0));
        if( num == 0 )
            pref_mul.push_back(1);
        else
            pref_mul.push_back(pref_mul.back() * num);
    }
    
    int getProduct(int k) {
        int r = int(pref_mul.size()) - 1;
        int l = r - k + 1;
        int number_of_zeros = pref_zeros[r] - pref_zeros[l - 1];
        if(number_of_zeros)
            return 0;
        return int(pref_mul[r] / pref_mul[l - 1]);
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */