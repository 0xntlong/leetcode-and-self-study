/**
1081. Smallest Subsequence of Distinct Characters
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

    Example :
    Input: s = "bcabc"
    Output: "abc"
 */



function smallestSubsequence(s: string): string {
    const freq = new Map<string, number>();
    const visited = new Set<string>();
    const stack: string[] = [];

    for (const c of s) {
        freq.set(c, (freq.get(c) ?? 0) + 1);
    }

    for (const c of s) {
        freq.set(c, (freq.get(c) ?? 0) - 1);

        if (visited.has(c)) {
            continue;
        }

        while (
            stack.length > 0 &&
            stack[stack.length - 1] > c &&
            (freq.get(stack[stack.length - 1]) ?? 0) > 0
        ) {
            visited.delete(stack.pop()!);
        }

        stack.push(c);
        visited.add(c);
    }

    return stack.join("");
}