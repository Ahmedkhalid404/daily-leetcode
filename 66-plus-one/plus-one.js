/**
 * @param {number[]} digits
 * @return {number[]}
 */
 let plusOne = function(digits) {
    for(let i = digits.length - 1; i > -1 ; i--) {
        if(digits[i] + 1 < 10){
            digits[i] ++;
            return digits;
        }

        digits[i] = 0;
    }
    digits.unshift(1);
    return digits;
};
