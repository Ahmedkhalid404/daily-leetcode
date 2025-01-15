class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset< 31 > num1_bits(num1),  res;
        int bits = int(bitset< 31 > (num2).count());
        for (int i = num1_bits.size() - 1; ( i > -1 ) and (bits > 0) ; --i) {
            if( num1_bits[i] )
                res[i] = true, bits --;
        }


        for (int i = 0; (i < num1_bits.size()) and (bits > 0) ; ++i) {
            if( (!num1_bits[i]) and (!res[i]) )
                res[i] = true, bits --;
        }

        for (int i = 0; (i < num1_bits.size()) and (bits > 0) ; ++i) {
            if( (num1_bits[i]) and (!res[i]) )
                res[i] = true, bits --;
        }

        return int(res.to_ulong());
    }
};