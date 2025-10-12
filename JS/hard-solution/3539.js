/**
3539. Find Sum of Array Product of Magical Sequences
    You are given two integers, m and k, and an integer array nums.
    A sequence of integers seq is called magical if:
    seq has a size of m.
    0 <= seq[i] < nums.length
    The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
    The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).
    Return the sum of the array products for all valid magical sequences.
    Since the answer may be large, return it modulo 10^9 + 7.
    A set bit refers to a bit in the binary representation of a number that has a value of 1.

    Example :
    Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]
    Output: 991600007
    Explanation:
    All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 10^13.
 */



/**
 * @param {number} m
 * @param {number} k
 * @param {number[]} nums
 * @return {number}
 */
var magicalSum = function(m, k, nums) {
    const MOD = BigInt(1000000007);
    const n = nums.length;
    const comp = Array.from({length: m + 1}, () => Array(m + 1).fill(0n));
    for(let i = 0;i <= m;i++){
        comp[i][0] = 1n; comp[i][i] = 1n;
        for(let j = 1; j < i; j++){
            comp[i][j] = (comp[i-1][j-1] + comp[i-1][j]) % MOD;
        }
    }
    const powA = Array.from({length: n}, () => Array(m+1).fill(1n));
    for(let i = 0; i < n; i++){
        powA[i][0] = 1n;
        const a = BigInt(nums[i]) % MOD;
        for(let t = 1; t <= m; t++){
            powA[i][t] = (powA[i][t - 1] * a) % MOD;
        }
    }
    const M = m;
    let cur = Array.from({length: M +1 }, () =>
        Array.from({length: M + 1}, () =>
            Array(M + 1).fill(0n)
        )
    );
    cur[M][0][0] = 1n;

    for(let i = 0; i < n; i++){
        let nxt = Array.from({length: M + 1}, () =>
            Array.from({length: M + 1}, () =>
                Array(M + 1).fill(0n)
            )
        );
        for(let r = 0;r <= M; r++){
            for(let flag = 0; flag <= M; flag++){
                for(let ones = 0; ones <= M; ones++){
                    let val = cur[r][flag][ones];
                    if(val === 0n)
                        continue;
                    for(let t = 0; t <= r; t++){
                        let newr = r - t;
                        let sum = flag + t;
                        let bit = sum & 1;
                        let newones = ones + bit;
                        if(newones > M) 
                            continue;
                        let newflag = sum >>> 1;
                        let mult = (comp[r][t] * powA[i][t]) % MOD;
                        let add = (val * mult) % MOD;
                        nxt[newr][newflag][newones] = (nxt[newr][newflag][newones] + add) % MOD;
                    }
                }
            }
        }
        cur = nxt;
    }

    let ans = 0n;
    for(let flag = 0; flag <= M; flag++){
        for(let ones = 0; ones <= M; ones++){
            let val = cur[0][flag][ones];
            if(val === 0n) 
                continue;
            let extra = popcount(flag);
            if(ones + extra === k){
                ans = (ans + val) % MOD;
            }
        }
    }
    return Number(ans);

    function popcount(x){
        let c = 0;
        while(x > 0){
            c += x & 1;
            x >>>= 1;
        }
        return c;
    }
};