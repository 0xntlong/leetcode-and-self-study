/**
135. Candy
    There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
    You are giving candies to these children subjected to the following requirements:
    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    Return the minimum number of candies you need to have to distribute the candies to the children.

    Example :
    Input: ratings = [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 */


function candy(ratings: number[]): number {
    const n = ratings.length;
    const c : number[] = new Array(n).fill(1);
    let cnt = 0;
    for (let i = 1; i < n; i++){
        if (ratings[i] > ratings[i -1]){
            c[i] = c[i - 1] + 1;
        }
    }
    for (let i = n - 1; i > 0; i--){
        if (ratings[i - 1] > ratings[i]){
            c[i - 1] = Math.max(c[i] + 1, c[i - 1]);
        }
        cnt += c[i - 1];
    }
    return cnt + c[n - 1];
};