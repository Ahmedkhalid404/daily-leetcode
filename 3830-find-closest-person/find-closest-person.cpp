class Solution {
public:
    int findClosest(int x, int y, int z) {
        return ( abs(z - x) < abs(z - y) ? 1 : ( abs(x - z) > abs(y - z) ? 2 : 0 ) );
    }
};