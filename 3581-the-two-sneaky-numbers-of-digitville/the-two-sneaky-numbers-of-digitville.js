/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    let freq = [];
    let res = [];

    for(let i = 0; i < nums.length; i++){
        if( freq[ nums[i] ] == undefined )
            freq[ nums[i] ] = 1;
        else 
            freq[ nums[i] ] ++;
        
        if( freq[ nums[i] ] == 2 )
            res.push(nums[i]);
        else if( freq[nums[i]] > 2 )
            res.splice( res.indexOf(nums[i]), 1 );
    }

    return res;

};