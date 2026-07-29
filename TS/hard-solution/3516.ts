/**
3518. Smallest Palindromic Rearrangement II
    You are given a palindromic string s and an integer k.
    Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
    Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
    
    Example:
    Input: s = "abba", k = 2
    Output: "baab"
    Explanation:
    The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
    Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".

 */


const INF = 1000001;
const N = 24;
const C: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
let pascalInitialized = false;

function initPascal(): void {
    if (pascalInitialized) 
            return;
    pascalInitialized = true;
    (C[0] as number[])[0] = 1;
    for (let i = 1; i < N; i++) {
        (C[i] as number[])[0] = (C[i] as number[])[i] = 1;
        for (let j = 1; j <= Math.floor(i / 2); j++) {
            (C[i] as number[])[j] = (C[i] as number[])[i - j] = (C[i - 1] as number[])[j - 1] + (C[i - 1] as number[])[j];
        }
    }
}

function comb(n: number, k: number): number {
    if (n < N && k < N && n >= 0 && k >= 0 && k <= n) 
        return C[n][k];
    if (k < 0 || k > n) return 0;
    if (2 * k > n) k = n - k;
    let ans = 1;
    for (let i = 1; i <= k; i++) {
        ans = ans * (n - i + 1) / i;
        if (ans >= INF) return INF;
    }
    return ans;
}

function perm(count: number[], sz: number): number {
    let ans = 1;
    for (let f of count) {
        if (f === 0) continue;
        ans *= comb(sz, f);
        if (ans >= INF) return INF;
        sz -= f;
    }
    return ans;
}

function smallestPalindrome(s: string, k: number): string {
    initPascal();
    const n = s.length;
    const ans: string[] = new Array(n).fill(' ');

    const count: number[] = new Array(26).fill(0);
    const n0 = Math.floor(n / 2);
    for (let i = 0; i < n0; i++) {
        count[s.charCodeAt(i) - 97]++;
    }

    if (n % 2 === 1) {
        ans[Math.floor(n / 2)] = s[Math.floor(n / 2)];
    }

    let ways = perm(count, n0);
    if (k > ways) 
        return "";

    let index = 0;
    let total = n0;

    for (let i = 0; i < n0; i++) {
        for (let c = 0; c < 26; c++) {
            if (count[c] === 0) 
                continue;

            const cnt = Math.floor(ways * count[c] / total);

            if (cnt >= k) {
                ans[index] = ans[n - 1 - index] = String.fromCharCode(97 + c);
                index++;
                ways = cnt;
                count[c]--;
                total--;
                break;
            } else {
                k -= cnt;
            }
        }
    }

    return ans.join('');
}

export {};