/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    
    function dfs(obj) {
        if (!obj) return false;
        if (typeof obj !== 'object') return obj;

        if( Array.isArray(obj) ){
            let newArray = [];
            for(let item of obj){
                let sub = dfs(item);
                if(sub !== false)
                    newArray.push(sub);
            }
            return newArray;
        }

        let newObj = {};
        for(const key in obj){
            let sub = dfs(obj[key]);
            if(sub !== false){
                newObj[key] = sub;
            }
        }

        return newObj;

    }

    return dfs(obj);

};