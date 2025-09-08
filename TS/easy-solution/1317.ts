/**
1317. Convert Integer to the Sum of Two No-Zero Integers
    No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
    Given an integer n, return a list of two integers [a, b] where:
    a and b are No-Zero integers.
    a + b = n
    The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

    Example :
    Input: n = 2
    Output: [1,1]
    Explanation: Let a = 1 and b = 1.
    Both a and b are no-zero integers, and a + b = 2 = n.
 */


function getNoZeroIntegers(n: number): number[] {
    const check = (n : number): boolean => {
        while (n > 0){
            if (n % 10 === 0){
                return false;
            }
            n = Math.floor(n / 10);
        }
        return true;
    };
    for (let j = 1; j < 10; j++){
        let i = n - j;
        if (check(i) && check(j)){
            return [i, j];
        }
    }
    return [];
};