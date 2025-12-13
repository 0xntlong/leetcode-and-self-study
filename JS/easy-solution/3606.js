/**
3606. Coupon Code Validator
    You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:
    code[i]: a string representing the coupon identifier.
    businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active.
    A coupon is considered valid if all of the following conditions hold:
    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.
    Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

    Example :

    Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

    Output: ["PHARMA5","SAVE20"]

    Explanation:

    First coupon is valid.
    Second coupon has empty code (invalid).
    Third coupon is valid.
    Fourth coupon has special character @ (invalid).
 */



/**
 * @param {string[]} code
 * @param {string[]} businessLine
 * @param {boolean[]} isActive
 * @return {string[]}
 */
var validateCoupons = function(code, businessLine, isActive) {
    let arr = Array.from({ length: 4 }, () => []);
    for(let i=0; i<code.length; i++){
        if(!isActive[i]) 
            continue
        if(!isValid(code[i])) 
            continue

        if(businessLine[i]==="electronics"){
            arr[0].push(code[i])
        } else if (businessLine[i]==="grocery"){
            arr[1].push(code[i])
        } else if (businessLine[i]==="pharmacy"){
            arr[2].push(code[i])
        } else if (businessLine[i]==="restaurant"){
            arr[3].push(code[i])
        } 
    }
    
    let res = []
    for(let a of arr){
        a.sort()
        res.push(...a)
    }
    return res
};

function isValid(code) {
  return /^[a-zA-Z0-9_]+$/.test(code);
};