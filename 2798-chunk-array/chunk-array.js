/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let chuncked = [];
    for(let i = 0; i < arr.length; i += size){
        let curr = [];
        for(let j = i; j < Math.min(i + size, arr.length); j ++){
            curr.push(arr[j]);
        }
        chuncked.push(curr);
    }
    return chuncked;
};
