/**
679. 24 Game
    You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
    You are restricted with the following rules:
    The division operator '/' represents real division, not integer division.
    For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
    For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
    You cannot concatenate numbers together
    For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
    Return true if you can get such expression that evaluates to 24, and false otherwise.

    Example 1:

    Input: cards = [4,1,8,7]
    Output: true
    Explanation: (8-4) * (7-1) = 24
 */




function judgePoint24(cards: number[]): boolean {
    const nums = cards.map(card => card * 1.0);
    return dfs(nums);
};
function dfs(nums: number[]): boolean {
  if (nums.length === 1){
    return Math.abs(nums[0] - 24.0) < 1e-6;
  }
  const n = nums.length;
  for (let i = 0; i < n; i++){
    for (let j = 0; j < n; j++){
      if (i === j) continue;
      const next: number[] = [];
      for (let k = 0; k < n; k++){
        if (k !== i && k !== j){
          next.push(nums[k]);
        }
      }
      const a = nums[i], b = nums[j];
      const res: number[] = [a + b, a - b, a * b];
      if (Math.abs(b) > 1e-6) res.push(a / b);
      if (Math.abs(a) > 1e-6) res.push(b / a);
      for (let val of res){
        next.push(val);
        if (dfs(next))
          return true;
        next.pop();
      }
    }
  }
  return false;
};