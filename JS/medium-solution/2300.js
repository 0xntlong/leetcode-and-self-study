/**
2300. Successful Pairs of Spells and Potions
    You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
    You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
    Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

    Example :

    Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    Output: [4,0,3]
    Explanation:
    - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
    - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
    - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
    Thus, [4,0,3] is returned.
 */



/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function(spells, potions, success) {
    const maxPotion = Math.max(...potions);
    const freq = new Array(maxPotion + 1).fill(0);

    for (const p of potions){
        freq[p]++;
    }

    for (let i = 1; i <= maxPotion; i++) {
        freq[i] += freq[i - 1];
    }
    const totalPotions = potions.length;
    const result = new Array(spells.length).fill(0);

    for (let i = 0; i < spells.length; i++) {
        const s = spells[i];
        const k = Math.floor((success + s - 1) / s);
        if (k <= maxPotion){
            result[i] = totalPotions - freq[k - 1];
        }
    }

    return result;
};