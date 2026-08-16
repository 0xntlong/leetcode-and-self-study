/**
2029. Stone Game IX
    Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.
    Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).
    Assuming both players play optimally, return true if Alice wins and false if Bob wins.
    Example :
    Input: stones = [2,1]
    Output: true
    Explanation: The game will be played as follows:
    - Turn 1: Alice can remove either stone.
    - Turn 2: Bob removes the remaining stone. 
    The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
 */



function stoneGameIX(stones: number[]): boolean {
    const count: number[] = [0, 0, 0];

    for (const stone of stones) {
        count[stone % 3]++;
    }

    if (count[0] % 2 === 0) {
        return count[1] > 0 && count[2] > 0;
    }

    return Math.abs(count[1] - count[2]) >= 3;
};