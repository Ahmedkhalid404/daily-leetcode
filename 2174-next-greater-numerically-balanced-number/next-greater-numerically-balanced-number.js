/**
 * @param {number} n
 * @return {number}
 */
var nextBeautifulNumber = n => {
    n ++;
    
    let isValid = n => {
        let freq = new Array(10).fill(0);
        for(let ch of n.toString()){
            freq[ ch - '0' ] ++;
        }

        for(let i in freq)
            if(freq[i])
                if( freq[i] != i ) 
                    return false;

        return true;
    };

    while(!isValid(n)) n ++;

    return n;
};