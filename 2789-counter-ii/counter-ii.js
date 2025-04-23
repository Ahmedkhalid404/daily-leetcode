/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
let initVal, x;
var createCounter = function(init) {
    x = init;
    initVal = init;

    const counter = {
        increment : function(){
            x ++;
            return x;
        },
        decrement : function(){
            x --;
            return x;
        },
        reset : function(){
            x = initVal;
            return x;
        }
    };
    return counter;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */