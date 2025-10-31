/**
 * @param {number} n
 * @return {number}
 */
var totalMoney = function(n) {
    let numberOf7s = parseInt(n / 7);
    let remaning = n % 7;

    let sumFrom1ToN = (n) =>  n * (n + 1) / 2;

    let sumFrom1To7 = sumFrom1ToN(7);
    let sum = sumFrom1To7 * numberOf7s + (sumFrom1ToN(numberOf7s - 1) * 7);

    let extra = sumFrom1ToN(remaning) + (numberOf7s * remaning);

    sum = sum + extra;

    return sum;
};