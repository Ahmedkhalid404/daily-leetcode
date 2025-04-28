/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(a, b) {
    let freq = new Map();
    let joined = [];

    for(let i = 0; i < a.length; i++){
        freq.set(a[i].id, i);
        joined.push(a[i]);
    }
    
    for(let i = 0; i < b.length; i++){
        console.log(b[i].id);
        if( freq.has(b[i].id) ){
            console.log("yes");
            let idx = freq.get(b[i].id);
            for(let j = 0; j < Object.keys(b[ i ]).length;j ++){
                joined[ idx ][ Object.keys(b[ i ])[j] ] = Object.values(b[i])[j];
            }
        } else {
            joined.push(b[i]);
            console.log("no");
        }
    }
    joined.sort((a,b) => a.id - b.id);
    return joined;
};