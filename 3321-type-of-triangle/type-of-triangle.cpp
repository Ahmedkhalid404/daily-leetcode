class Solution {
public:
    string triangleType(vector<int>& a) {
        ranges::sort(a);
        if( !(a[0] + a[1] > a[2]) ) return "none"s;
        if(a[0] == a[1] and a[0] == a[2]) return "equilateral"s;
        if(a[0] == a[1] or a[0] == a[2] or a[1] == a[2]) return "isosceles"s;
        return "scalene"s;
    }
};