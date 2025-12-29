/**
756. Pyramid Transition Matrix
    You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
    To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
    For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
    You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
    Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

    Example :
    Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
    Output: true
    Explanation: The allowed triangular patterns are shown on the right.
    Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
    There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
 */



function pyramidTransition(bottom: string, allowed: string[]): boolean {
    const map = new Map<string, string[]>();
    for (const t of allowed) {
        const key = t.slice(0, 2);
        if (!map.has(key)) map.set(key, []);
        map.get(key)!.push(t[2]);
    }

    const memo = new Map<string, boolean>();

    const dfs = (row: string): boolean => {
        if (memo.has(row)) return memo.get(row)!;
        if (row.length === 1) {
            memo.set(row, true);
            return true;
        }

        const n = row.length;
        for (let i = 0; i < n - 1; i++) {
            if (!map.has(row.slice(i, i + 2))) {
                memo.set(row, false);
                return false;
            }
        }

        const helper = (i: number, curr: string): boolean => {
            if (i === n - 1) return dfs(curr);
            const pair = row.slice(i, i + 2);
            for (const c of map.get(pair)!) {
                if (helper(i + 1, curr + c)) return true;
            }
            return false;
        };

        const res = helper(0, "");
        memo.set(row, res);
        return res;
    };

    return dfs(bottom);
};