/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    let freq = new Map();
    let res = new Set();

    for(let el of nums){
        freq.set(el, ( freq.get(el) ?? 0 ) + 1 );
        if( freq.get(el) == 2 ){
            res.add(el);
        } else if( freq.get(el) > 2 ){
            res.delete(el);
        }
    }

    return [...res];

};