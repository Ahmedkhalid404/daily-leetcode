/**
 * @param {string} s
 * @return {boolean}
 */
let hasSameDigits = s => {
    while( s.length > 2 ){
        let res = '';
        for(let i = 0; i < s.length - 1; i++) {
            res += ( (+s[i] + +s[i + 1]) % 10 );
        }
        s = res;
    }
    return s[0] === s[1];
};
