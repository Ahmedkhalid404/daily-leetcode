/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let res = 0;
    let getLastIdxEqToMe = first =>{
        let i = first + 1;
        let mx = neededTime[first];
        let sum = neededTime[first];
        for(; i < colors.length; i++){
            if( colors[i] != colors[first] ){
                break;
            }
            sum += neededTime[i];
            mx = Math.max(mx, neededTime[i]);
        }
        return [i, sum, mx];
    };

    for(let i = 0; i < colors.length;){
        let [idx, sum, mx] = getLastIdxEqToMe(i);
        i = idx;
        res += sum - mx;
    }

    return res;
};