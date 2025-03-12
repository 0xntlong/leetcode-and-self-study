/**
2629. Function Composition
    Given an array of functions [f1, f2, f3, ..., fn], return a new function fn that is the function composition of the array of functions.
    The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).
    The function composition of an empty list of functions is the identity function f(x) = x.
    You may assume each function in the array accepts one integer as input and returns one integer as output.

    Example :
    Input: functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
    Output: 65
    Explanation:
    Evaluating from right to left ...
    Starting with x = 4.
    2 * (4) = 8
    (8) * (8) = 64
    (64) + 1 = 65
 */


type F = (x: number) => number;

function compose(functions: F[]): F {
    return function(x:number) : number {
        if (functions.length === 0)
            return x;
        let res = x;
        for (let i = functions.length - 1; i >= 0; i--){
            res = functions[i](res);
        }
        return res;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */