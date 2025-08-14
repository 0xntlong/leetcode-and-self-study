
/*
2264. Largest 3-Same-Digit Number in String
    You are given a string num representing a large integer. An integer is good if it meets the following conditions:
    It is a substring of num with length 3.
    It consists of only one unique digit.
    Return the maximum good integer as a string or an empty string "" if no such integer exists.
    Note:
    A substring is a contiguous sequence of characters within a string.
    There may be leading zeroes in num or a good integer.

    Example :
    Input: num = "6777133339"
    Output: "777"
    Explanation: There are two distinct good integers: "777" and "333".
    "777" is the largest, so we return "777".
*/



function largestGoodInteger(num: string): string {
    let res = "";
    for (let i = 0; i < num.length - 2; i++){
        if (num[i] === num[i + 1] && num[i + 1] === num[i + 2]){
            let temp = num.substring(i, i + 3);
            if (!res || temp > res){
                res = temp;
            }
        }
    }
    return res;
};