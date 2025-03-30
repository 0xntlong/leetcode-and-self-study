/**
763. Partition Labels
    You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
    Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
    Return a list of integers representing the size of these parts.
    Example :
    Input: s = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij".
    This is a partition so that each letter appears in at most one part.
    A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 */



    function partitionLabels(s: string): number[] {
        const n = s.length;
        const alphabet: number[] = new Array(26).fill(-1);
        for (let i = 0; i < n; i++){
            alphabet[s.charCodeAt(i) - 97] = i;
        }
        const res: number[] = [];
        let start = 0, end = -1;
        for (let i = 0; i < n; i++){
            end = Math.max(end, alphabet[s.charCodeAt(i) - 97]);
            if (i === end){
                res.push(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    };