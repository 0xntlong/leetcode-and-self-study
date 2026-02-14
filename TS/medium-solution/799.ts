/**
799. Champagne Tower
    We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.
    Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
    For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
    Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)

    Example :
    Input: poured = 1, query_row = 1, query_glass = 1
    Output: 0.00000
    Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
 */



function champagneTower(poured: number, query_row: number, query_glass: number): number {
    let prev: number[] = [poured];
    for (let i = 1; i <= query_row; i++) {
        const curr: number[] = new Array(i + 1).fill(0);
        for (let j = 0; j < i; j++) {
            const extra = prev[j] - 1;
            if (extra > 0) {
                const half = extra * 0.5;
                curr[j] += half;
                curr[j + 1] += half;
            }
        }
        prev = curr;
    }

    return Math.min(1, prev[query_glass]);
};