/**
3170. Lexicographically Minimum String After Removing Stars
    You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
    While there is a '*', do the following operation:
    Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
    Return the lexicographically smallest resulting string after removing all '*' characters.

    Example :
    Input: s = "aaba*"
    Output: "aab"
    Explanation:
    We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 */



function clearStars(s: string): string {
    let n: number = s.length;
    let alpha: Array<number[]> = Array.from({ length: 26 }, () => []);
    let s0: number = 0;
    let sArray: string[] = s.split('');
    
    for (let i = 0; i < n; i++) {
        let c: string = sArray[i];
        
        if (c !== '*') {
            alpha[c.charCodeAt(0) - 'a'.charCodeAt(0)].push(s0);
            sArray[s0] = c;
            s0++;
        } else {
            for (let x = 0; x < 26; x++) {
                if (alpha[x].length > 0) {
                    let k: number = alpha[x].pop()!;
                    sArray[k] = '';
                    break;
                }
            }
        }
    }
    
    let j: number = 0; 
    for (let i = 0; i < s0; i++) {
        if (sArray[i] >= 'a') {
            sArray[j] = sArray[i];
            j++;
        }
    }
    
    sArray = sArray.slice(0, j);
    return sArray.join('');
}
