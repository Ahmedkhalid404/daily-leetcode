/**
 * @param {Function} fn
 * @return {Function}
 */
 const MAX_N = 1e5 + 5;
function memoize(fn) {

    let memo = new Map();
    
    return function(...args) {
        let curr = memo[args];
        if(typeof curr === typeof undefined){
            memo[args] = fn(...args);
        }

        return memo[args];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */