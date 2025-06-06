/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    const testObj = {
        toBe : (x)=>{
            if( x === val )
                return true;
            throw new Error('Not Equal');
        },
        notToBe : (x) => {
            if( x !== val )
                return true;
            throw new Error('Equal');
        }
    }
    return testObj;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */