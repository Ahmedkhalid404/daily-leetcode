/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let myObj = {};
    for(let i = 0; i < this.length; i++){
        const key = fn(this[i]);
        if( ! (key in myObj) ){
            myObj[key] = [];
        }
        myObj[key].push(this[i]);
    }
    return myObj;

};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */