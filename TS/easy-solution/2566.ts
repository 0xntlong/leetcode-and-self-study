/**
2566. Maximum Difference by Remapping a Digit
    You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
    Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
    Notes:
    When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
    Bob can remap a digit to itself, in which case num does not change.
    Bob can remap different digits for obtaining minimum and maximum values respectively.
    The resulting number after remapping can contain leading zeroes.

    Example:
    Input: num = 11891
    Output: 99009
    Explanation: 
    To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
    To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
    The difference between these two numbers is 99009.
*/



function minMaxDifference(num: number): number {
    const numStr : string = num.toString();
    let maxArr : string[] = numStr.split('');
    for (let i = 0; i < maxArr.length; i++){
        if (maxArr[i] !== '9'){
            const target: string = maxArr[i];
            for (let j = 0; j < maxArr.length; j++){
                if (maxArr[j] === target){
                    maxArr[j] = '9';
                }
            }
            break;
        }
    }
    const maxNum : number = parseInt(maxArr.join(''));
    let minArr : string[] = numStr.split('');
    for (let i = 0; i < minArr.length; i++){
        if (minArr[i] !== '0'){
            const target: string = minArr[i];
            for (let j = 0; j < minArr.length; j++){
                if (minArr[j] === target){
                    minArr[j] = '0';
                }
            }
            break;
        }
    }
    const minNum : number = parseInt(minArr.join(''));
    return maxNum - minNum;
};