/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let curr = 0n;
    for (let el of digits) {
        curr *= 10n;
        curr += BigInt(el);
    }
    curr ++;
    
    return curr.toString().split('').map(c => +c) ;
};