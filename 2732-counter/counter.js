/**
 * @param {number} n
 * @return {Function} counter
 */
let x;
var createCounter = function(n) {
    x = n;
    return function() {
        x = x + 1;
        return x - 1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */