/*
3085. Minimum Deletions to Make String K-Special
    You are given a string word and an integer k.
    We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
    Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
    Return the minimum number of characters you need to delete to make word k-special.

    Example :
    Input: word = "aabcaba", k = 0
    Output: 3
    Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.
 */



function minimumDeletions(word: string, k: number): number {
    const freq = new Array(26).fill(0);
    for (const c of word){
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    freq.sort((a, b) => a - b);
    let rm = 0, ans = word.length;
    for (let i = 0; i < 26; i++){
        if (freq[i] === 0)
            continue;
        let res = rm;
        let minF = freq[i];
        for (let j = 25; j > i; j--){
            if (freq[j] - minF <= k)
                break;
            res += freq[j] - minF - k;
        }
        ans = Math.min(ans, res);
        rm += freq[i];
    }
    return ans;
};